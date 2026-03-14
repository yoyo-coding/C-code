#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>
#include <cctype>
#include <stdexcept>

using namespace std;

/* ===================== Token ===================== */

enum class TokenType {
    LET, PRINT,
    IDENT, NUMBER,
    PLUS, MINUS, STAR, SLASH,
    EQUAL, SEMICOLON,
    LPAREN, RPAREN,
    END
};

struct Token {
    TokenType type;
    string lexeme;
};

/* ===================== Lexer ===================== */

class Lexer {
public:
    explicit Lexer(const string& src) : source(src) {}

    vector<Token> tokenize() {
        vector<Token> tokens;
        while (!isAtEnd()) {
            skipWhitespace();
            if (isAtEnd()) break;
            tokens.push_back(nextToken());
        }
        tokens.push_back({TokenType::END, ""});
        return tokens;
    }

private:
    string source;
    size_t pos = 0;

    bool isAtEnd() const {
        return pos >= source.size();
    }

    char peek() const {
        return source[pos];
    }

    char advance() {
        return source[pos++];
    }

    void skipWhitespace() {
        while (!isAtEnd() && isspace(peek())) advance();
    }

    Token identifier() {
        size_t start = pos;
        while (!isAtEnd() && isalnum(peek())) advance();
        string text = source.substr(start, pos - start);

        if (text == "let")   return {TokenType::LET, text};
        if (text == "print") return {TokenType::PRINT, text};
        return {TokenType::IDENT, text};
    }

    Token number() {
        size_t start = pos;
        while (!isAtEnd() && isdigit(peek())) advance();
        if (!isAtEnd() && peek() == '.') {
            advance();
            while (!isAtEnd() && isdigit(peek())) advance();
        }
        return {TokenType::NUMBER, source.substr(start, pos - start)};
    }

    Token nextToken() {
        char c = advance();
        if (isalpha(c)) {
            pos--;
            return identifier();
        }
        if (isdigit(c)) {
            pos--;
            return number();
        }

        switch (c) {
            case '+': return {TokenType::PLUS, "+"};
            case '-': return {TokenType::MINUS, "-"};
            case '*': return {TokenType::STAR, "*"};
            case '/': return {TokenType::SLASH, "/"};
            case '=': return {TokenType::EQUAL, "="};
            case ';': return {TokenType::SEMICOLON, ";"};
            case '(': return {TokenType::LPAREN, "("};
            case ')': return {TokenType::RPAREN, ")"};
        }

        throw runtime_error(string("Unexpected character: ") + c);
    }
};

/* ===================== AST ===================== */

struct Expr {
    virtual ~Expr() = default;
};

struct NumberExpr : Expr {
    double value;
    explicit NumberExpr(double v) : value(v) {}
};

struct VariableExpr : Expr {
    string name;
    explicit VariableExpr(string n) : name(move(n)) {}
};

struct BinaryExpr : Expr {
    unique_ptr<Expr> left;
    Token op;
    unique_ptr<Expr> right;

    BinaryExpr(unique_ptr<Expr> l, Token o, unique_ptr<Expr> r)
        : left(move(l)), op(o), right(move(r)) {}
};

struct Stmt {
    virtual ~Stmt() = default;
};

struct LetStmt : Stmt {
    string name;
    unique_ptr<Expr> initializer;
};

struct PrintStmt : Stmt {
    unique_ptr<Expr> expr;
};

/* ===================== Parser ===================== */

class Parser {
public:
    explicit Parser(const vector<Token>& t) : tokens(t) {}

    vector<unique_ptr<Stmt>> parse() {
        vector<unique_ptr<Stmt>> stmts;
        while (!check(TokenType::END)) {
            stmts.push_back(statement());
        }
        return stmts;
    }

private:
    vector<Token> tokens;
    size_t current = 0;

    bool check(TokenType type) const {
        return tokens[current].type == type;
    }

    Token advance() {
        return tokens[current++];
    }

    Token previous() const {
        return tokens[current - 1];
    }

    bool match(TokenType type) {
        if (check(type)) {
            advance();
            return true;
        }
        return false;
    }

    void consume(TokenType type, const string& msg) {
        if (check(type)) {
            advance();
            return;
        }
        throw runtime_error(msg);
    }

    unique_ptr<Stmt> statement() {
        if (match(TokenType::LET))   return letStatement();
        if (match(TokenType::PRINT)) return printStatement();
        throw runtime_error("Expected statement");
    }

    unique_ptr<Stmt> letStatement() {
        Token name = advance();
        consume(TokenType::EQUAL, "Expected '='");
        auto expr = expression();
        consume(TokenType::SEMICOLON, "Expected ';'");

        auto stmt = make_unique<LetStmt>();
        stmt->name = name.lexeme;
        stmt->initializer = move(expr);
        return stmt;
    }

    unique_ptr<Stmt> printStatement() {
        auto expr = expression();
        consume(TokenType::SEMICOLON, "Expected ';'");

        auto stmt = make_unique<PrintStmt>();
        stmt->expr = move(expr);
        return stmt;
    }

    unique_ptr<Expr> expression() {
        return term();
    }

    unique_ptr<Expr> term() {
        auto expr = factor();
        while (match(TokenType::PLUS) || match(TokenType::MINUS)) {
            Token op = previous();
            auto right = factor();
            expr = make_unique<BinaryExpr>(move(expr), op, move(right));
        }
        return expr;
    }

    unique_ptr<Expr> factor() {
        auto expr = primary();
        while (match(TokenType::STAR) || match(TokenType::SLASH)) {
            Token op = previous();
            auto right = primary();
            expr = make_unique<BinaryExpr>(move(expr), op, move(right));
        }
        return expr;
    }

    unique_ptr<Expr> primary() {
        if (match(TokenType::NUMBER))
            return make_unique<NumberExpr>(stod(previous().lexeme));
        if (match(TokenType::IDENT))
            return make_unique<VariableExpr>(previous().lexeme);
        if (match(TokenType::LPAREN)) {
            auto expr = expression();
            consume(TokenType::RPAREN, "Expected ')'");
            return expr;
        }
        throw runtime_error("Expected expression");
    }
};

/* ===================== Interpreter ===================== */

class Interpreter {
public:
    void run(const vector<unique_ptr<Stmt>>& stmts) {
        for (const auto& s : stmts) execute(s.get());
    }

private:
    unordered_map<string, double> env;

    double eval(Expr* expr) {
        if (auto n = dynamic_cast<NumberExpr*>(expr))
            return n->value;
        if (auto v = dynamic_cast<VariableExpr*>(expr))
            return env.at(v->name);
        if (auto b = dynamic_cast<BinaryExpr*>(expr)) {
            double l = eval(b->left.get());
            double r = eval(b->right.get());
            switch (b->op.type) {
                case TokenType::PLUS:  return l + r;
                case TokenType::MINUS: return l - r;
                case TokenType::STAR:  return l * r;
                case TokenType::SLASH: return l / r;
                default: break;
            }
        }
        throw runtime_error("Invalid expression");
    }

    void execute(Stmt* stmt) {
        if (auto let = dynamic_cast<LetStmt*>(stmt)) {
            env[let->name] = eval(let->initializer.get());
        } else if (auto p = dynamic_cast<PrintStmt*>(stmt)) {
            cout << eval(p->expr.get()) << endl;
        }
    }
};

/* ===================== main ===================== */

int main() {
    string source =
        "let a = 1 + 2 * 3;"
        "let b = (a + 4) / 2;"
        "print(a);"
        "print(b);";

    Lexer lexer(source);
    auto tokens = lexer.tokenize();

    Parser parser(tokens);
    auto program = parser.parse();

    Interpreter interpreter;
    interpreter.run(program);

    return 0;
}