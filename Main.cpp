#include <iostream>
#include <string>
#include <vector>
#include <map>

enum class TokenType {
    NUM,
    ID,
    L_PAREN,
    R_PAREN,
    PLUS,
    MULTIPLY,
    EQUAL,
    IF,
    LAMBDA,
    DEF,
    END
};

class Token {
private:
    TokenType type;
    int value;
public:
    Token(TokenType type) : type{type} {}
};

Token findOp(const char c) {
    std::map<char, TokenType> operatorMap = {
        { '+', TokenType::PLUS },
        { '*', TokenType::MULTIPLY },
    };
    return Token(operatorMap.find(c));
}

std::vector<Token> tokenize(std::string str) {
    std::vector<Token> tokens;

    for (const char& c : str){
        tokens.push_back(findOp(c));
    }

    return std::vector<Token>();
}

int main() {



    return 0;
}