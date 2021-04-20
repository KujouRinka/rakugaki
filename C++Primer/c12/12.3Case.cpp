#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <memory>

// I think code on book don't meet what this case except
// I have mark "*" char where I have modified code.

class QueryResult;

std::ostream &print(std::ostream &os, const QueryResult &qr);


class TextQuery {
public:
    using line_no = std::vector<std::string>::size_type;

    explicit TextQuery(std::ifstream &is);

    QueryResult query(const std::string &sought) const;

private:
    std::shared_ptr<std::vector<std::string>> file;

    std::map<std::string, std::shared_ptr<std::vector<line_no>>> wm;    // *
};


class QueryResult {
    friend std::ostream &print(std::ostream &os, const QueryResult &qr);

public:
    QueryResult(std::string s,
                std::shared_ptr<std::vector<TextQuery::line_no>> p,     // *
                std::shared_ptr<std::vector<std::string>> f) :
            sought(s), lines(p), file(f) {}

private:
    std::string sought;
    std::shared_ptr<std::vector<TextQuery::line_no>> lines;     // *
    std::shared_ptr<std::vector<std::string>> file;
};


TextQuery::TextQuery(std::ifstream &is) {
    std::string text;

    // There is no such statement in the book,
    // but dereference will cause error so I add it.
    file = std::make_shared<std::vector<std::string>>();    // *

    while (std::getline(is, text)) {
        file->push_back(text);
        auto n = file->size() - 1;
        std::istringstream line(text);
        std::string word;
        while (line >> word) {
            auto &lines = wm[word];
            if (!lines)
                lines.reset(new std::vector<line_no>);
            lines->push_back(n);
        }
    }
}

QueryResult TextQuery::query(const std::string &sought) const {
    static std::shared_ptr<std::vector<line_no>> nodata(new std::vector<line_no>);

    auto loc = wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, loc->second, file);
}

std::ostream &print(std::ostream &os, const QueryResult &qr) {
    os << qr.sought << " occurs " << qr.lines->size() << " "
       << "time(s)" << std::endl;

    std::set<TextQuery::line_no> dataSet(qr.lines->begin(), qr.lines->end());   // *
    for (auto num : dataSet)    // *
        os << "\t(line " << num + 1 << ") "
           << *(qr.file->begin() + num) << std::endl;
    return os;
}


void runQueries(std::ifstream &infile) {
    TextQuery tq(infile);

    while (true) {
        std::cout << "enter word to look for, or q to quit: ";
        std::string s;
        if (!(std::cin >> s) || s == "q") break;
        print(std::cout, tq.query(s)) << std::endl;
    }
}

int main() {
    std::ifstream fs("r.in");
    runQueries(fs);
    return 0;
}
