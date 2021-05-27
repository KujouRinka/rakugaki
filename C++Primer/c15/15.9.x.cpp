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
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;    // word map
};

class QueryResult {
    // Store result of querying in lines.
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
                lines.reset(new std::set<line_no>);
            lines->insert(n);
        }
    }
}

QueryResult TextQuery::query(const std::string &sought) const {
    // return result QueryResult
    static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);

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
Query operator&(const Query &lhs, const Query &rhs);
Query operator|(const Query &lhs, const Query &rhs);

class Query {
    friend Query inline operator~(const Query &rhs);
    friend Query inline operator&(const Query &lhs, const Query &rhs);
    friend Query inline operator|(const Query &lhs, const Query &rhs);
public:
    inline Query(std::string &q);

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
Query::Query(std::string &q) : q(new WordQuery(q)) {}

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

int main() {
    return 0;
}
