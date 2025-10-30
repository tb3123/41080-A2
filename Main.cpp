#include <iostream>
#include <string>
#include <vector>
#include <map>

enum class TokenType {
    NUMBER,
    ID,

    L_PAREN,
    R_PAREN,

    PLUS,
    MINUS,
    MULTIPLY,
    EQUALS,

    IF,
    LAMBDA,
    DEF,

    END
};

class Token {
public:
    TokenType type;
    std::string value;
public:
    Token(TokenType type) : type{type}, value{""} {}
    Token(TokenType type, std::string value) : type{type}, value{value} {}

    friend std::ostream& operator<<(std::ostream& os, const Token& token) {
        os << "{";
        switch(token.type) {
            case TokenType::PLUS:
            {
                os << "plus";
                break;
            }
            case TokenType::MINUS:
            {
                os << "minus";
                break;
            }
            case TokenType::MULTIPLY:
            {
                os << "multiply";
                break;
            }
            case TokenType::EQUALS:
            {
                os << "equals";
                break;
            }
            case TokenType::NUMBER:
            {
                os << "number";
                break;
            }
            default:
            {
                os << "unknown";
                break;
            }
        }
        os << "}";

        return os;
    }
};

Token findOp(const char c) {
    std::map<char, TokenType> operatorMap = {
        { '+', TokenType::PLUS },
        { '*', TokenType::MULTIPLY },
    };

    return Token(operatorMap[c]);
}

bool digit(char c) {
    return (c >= 48 && c <= 57);
}

std::vector<Token> tokenize(std::string str) {
    std::vector<Token> tokens;

    for (const char& c : str){
        // whitespace
        if(c == ' ') continue;

        if(c == '(') {
            tokens.push_back(Token(TokenType::L_PAREN));
            continue;
        }
        if(c == ')') {
            tokens.push_back(Token(TokenType::R_PAREN));
            continue;
        }

        if(digit(c)) {
            tokens.push_back(Token(TokenType::NUMBER, std::to_string(c)));
            continue;
        }

        if(c == '+') {
            tokens.push_back(Token(TokenType::PLUS));
            continue;
        }
        if(c == '-') {
            tokens.push_back(Token(TokenType::MINUS));
            continue;
        }
        if(c == '*') {
            tokens.push_back(Token(TokenType::MULTIPLY));
            continue;
        }
        if(c == '=') {
            tokens.push_back(Token(TokenType::EQUALS));
            continue;
        }
    }

    return tokens;
}

int main() {
    std::string str = "3 * 4 - (4 + 6)";

    std::vector<Token> tokens = tokenize(str);
    for(auto& token : tokens) {
        std::cout << token << '\n';
    }

    return 0;
}