#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <memory>
#include <algorithm>
#include <cctype>

// START TextQuery part
class QueryResult;

class TextQuery {
public:
    using line_no = std::vector<std::string>::size_type;
    explicit TextQuery(std::istream &is);
    QueryResult query(const std::string &sought) const;

private:
    std::shared_ptr<std::vector<std::string>> file;     // store file data
    // word map, which store lines each word appear.
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

class QueryResult {
    // Store result of querying in lines.
    friend std::ostream &print(std::ostream &os, const QueryResult &qr);
public:
    QueryResult(std::string s,
                std::shared_ptr<std::set<TextQuery::line_no>> p,
                std::shared_ptr<std::vector<std::string>> f) :
            sought(s), lines(p), file(f) {}

    // hope this to work well. God bless!
    std::set<TextQuery::line_no>::iterator begin() {
        return lines->begin();
    }
    std::set<TextQuery::line_no>::iterator end() {
        return lines->end();
    }
    std::shared_ptr<std::vector<std::string>> get_file() {
        return file;
    }

private:
    std::string sought;     // dist word
    std::shared_ptr<std::set<TextQuery::line_no>> lines;     // result lines
    std::shared_ptr<std::vector<std::string>> file;     // store file data
};

std::string proc_word(const std::string &s) {
    // add this function to delete non-alpha char of s
    std::string::size_type start = 0;
    decltype(start) backSpace = 0;
    for (auto &c : s) {
        if (isalpha(c))
            break;
        ++start;
    }
    for (auto it = s.crbegin(); it != s.crend(); ++it) {
        if (isalpha(*it))
            break;
        ++backSpace;
    }
    return s.substr(start, s.size() - backSpace - start);
}

TextQuery::TextQuery(std::istream &is) {
    // read file data to file obj.
    std::string text;

    // There is no such statement in the book,
    // but dereference will cause error so I add it.
    file = std::make_shared<std::vector<std::string>>();

    while (std::getline(is, text)) {
        file->push_back(text);
        auto n = file->size() - 1;
        std::istringstream line(text);
        std::string word;
        while (line >> word) {
            word = proc_word(word);
            auto &lines = wm[word];
            if (!lines)
                lines.reset(new std::set<line_no>);
            lines->insert(n);
        }
    }
}

QueryResult TextQuery::query(const std::string &sought) const {
    // construct a QueryResult, and
    // return result QueryResult.
    static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);

    auto loc = wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, loc->second, file);
}
// END TextQuery part


class Query_base {
    friend class Query;
protected:
    using line_no = TextQuery::line_no;
    virtual ~Query_base() = default;

private:
    // Execute and return result
    virtual QueryResult eval(const TextQuery &t) const = 0;
    // Generate querying string ver
    virtual std::string rep() const = 0;
};

// START Query part
class WordQuery;
class Query;
Query operator~(const Query &rhs);
Query operator&(const Query &lhs, const Query &rhs);
Query operator|(const Query &lhs, const Query &rhs);

class Query {
    friend Query inline operator~(const Query &rhs);
    friend Query inline operator&(const Query &lhs, const Query &rhs);
    friend Query inline operator|(const Query &lhs, const Query &rhs);
public:
    inline Query(const std::string &q);

    QueryResult eval(const TextQuery &t) const {
        return q->eval(t);
    }
    std::string rep() const { return q->rep(); }

private:
    Query(std::shared_ptr<Query_base> query) : q(query) {}
    std::shared_ptr<Query_base> q;
};

std::ostream &operator<<(std::ostream &os, const Query &query) {
    return os << query.rep();
}


class WordQuery : public Query_base {
    friend class Query;
private:
    WordQuery(const std::string &s) : query_word(s) {}

    QueryResult eval(const TextQuery &t) const override {
        return t.query(query_word);
    }
    std::string rep() const override {
        return query_word;
    }

    std::string query_word;
};

inline
Query::Query(const std::string &q) : q(new WordQuery(q)) {}

class NotQuery : public Query_base {
    friend Query operator~(const Query &rhs);
private:
    NotQuery(const Query &q) : query(q) {}

    QueryResult eval(const TextQuery &t) const;
    std::string rep() const override { return "~(" + query.rep() + ")"; }

    Query query;
};


class BinaryQuery : public Query_base {
protected:
    BinaryQuery(const Query &q1, const Query &q2, std::string s) :
            lhs(q1), rhs(q2), opSym(s) {}

    std::string rep() const { return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")"; }

    Query lhs, rhs;
    std::string opSym;
};

class AndQuery : public BinaryQuery {
    friend inline Query operator&(const Query &lhs, const Query &rhs);
private:
    AndQuery(const Query &left, const Query &right) :
            BinaryQuery(left, right, "&") {}

    QueryResult eval(const TextQuery &t) const;
};

class OrQuery : public BinaryQuery {
    friend inline Query operator|(const Query &lhs, const Query &rhs);
private:
    OrQuery(const Query &left, const Query &right) :
            BinaryQuery(left, right, "|") {}

    QueryResult eval(const TextQuery &t) const;
};

inline Query operator~(const Query &rhs) {
    // Implicit use constructor
    return std::shared_ptr<Query_base>(new NotQuery(rhs));
}

inline Query operator&(const Query &lhs, const Query &rhs) {
    return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

inline Query operator|(const Query &lhs, const Query &rhs) {
    return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

QueryResult OrQuery::eval(const TextQuery &t) const {
    auto left = lhs.eval(t), right = rhs.eval(t);
    auto ret_lines = std::make_shared<std::set<line_no>>(left.begin(), left.end());
    ret_lines->insert(right.begin(), right.end());
    return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult AndQuery::eval(const TextQuery &t) const {
    auto left = lhs.eval(t), right = rhs.eval(t);
    auto ret_lines = std::make_shared<std::set<line_no>>();
    std::set_intersection(left.begin(), left.end(),
                          right.begin(), right.end(),
                          std::inserter(*ret_lines, ret_lines->begin()));
    return QueryResult(rep(), ret_lines, left.get_file());
}

QueryResult NotQuery::eval(const TextQuery &t) const {
    auto result = query.eval(t);
    auto ret_lines = std::make_shared<std::set<line_no>>();
    auto line_size = result.get_file()->size();
    auto beg = result.begin(), end = result.end();
    for (std::size_t n = 0; n < line_size; ++n) {
        if (beg == end || *beg != n)
            ret_lines->insert(n);
        else if (beg != end)
            ++beg;
    }
    return QueryResult(rep(), ret_lines, result.get_file());
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

int main() {
    std::ifstream ifs("read.in");
    TextQuery t(ifs);
    Query q = ~(Query("Alice") | Query("Daddy"));
    print(std::cout, q.eval(t));
    return 0;
}
