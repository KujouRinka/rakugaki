#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <memory>

// START TextQuery part
class QueryResult;

class TextQuery {
public:
    using line_no = std::vector<std::string>::size_type;
    explicit TextQuery(std::ifstream &is);
    QueryResult query(const std::string &sought) const;

private:
    std::shared_ptr<std::vector<std::string>> file;     // store file data
    std::map<std::string, std::shared_ptr<std::vector<line_no>>> wm;    // word map
};

class QueryResult {
    // Store result of querying in lines.
public:
    QueryResult(std::string s,
                std::shared_ptr<std::vector<TextQuery::line_no>> p,
                std::shared_ptr<std::vector<std::string>> f) :
            sought(s), lines(p), file(f) {}

private:
    std::string sought;     // dist word
    std::shared_ptr<std::vector<TextQuery::line_no>> lines;     // result lines
    std::shared_ptr<std::vector<std::string>> file;     // store file data
};


TextQuery::TextQuery(std::ifstream &is) {
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
            auto &lines = wm[word];
            if (!lines)
                lines.reset(new std::vector<line_no>);
            lines->push_back(n);
        }
    }
}

QueryResult TextQuery::query(const std::string &sought) const {
    // return result QueryResult
    static std::shared_ptr<std::vector<line_no>> nodata(new std::vector<line_no>);

    auto loc = wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, loc->second, file);
}

class Query_base {
    friend class Query;
protected:
    using line_no = TextQuery::line_no;
    virtual ~Query_base() = default;

private:
    // Execute and return result
    virtual QueryResult eval(const TextQuery &) const = 0;
    // Generate querying string ver
    virtual std::string rep() const = 0;
};
// END TextQuery part


// START Query part
class WordQuery;
class Query;
Query operator~(const Query &rhs);
Query operator|(const Query &lhs, const Query &rhs);
Query operator&(const Query &lhs, const Query &rhs);

class Query {
    friend Query operator~(const Query &rhs);
    friend Query operator|(const Query &lhs, const Query &rhs);
    friend Query operator&(const Query &lhs, const Query &rhs);
public:
    inline Query(std::string &q);

    QueryResult eval(const TextQuery &t) const {
        return q->eval(t);
    }
    std::string rep() const { return q->rep(); }

private:
    Query(std::shared_ptr<Query_base> &query) : q(query) {}
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
Query::Query(std::string &q) : q(new WordQuery(q)) {}

class NotQuery : public Query_base {
    friend Query operator~(const Query &rhs);
private:
    NotQuery(const Query &q) : query(q) {}

    QueryResult eval(const TextQuery &t) const;
    std::string rep() const override { return "~(" + query.rep() + ")"; }

    Query query;
};

inline Query operator~(const Query &rhs) {

}

inline Query operator|(const Query &lhs, const Query &rhs) {

}

inline Query operator&(const Query &lhs, const Query &rhs) {

}
