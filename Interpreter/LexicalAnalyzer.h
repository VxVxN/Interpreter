#pragma once

#include <string>
#include <list>
#include <cctype>

#include "Token.h"

class LexicalAnalyzer
{
public:
	LexicalAnalyzer(std::string input);

	std::list<Token> tokenList;

	std::list<Token> tokenize();
private:
	std::string _input;
	const std::string OPERATOR_CHARS = "+-*/()=";
	TokenType OPERATOR_TOKENS[7] = {
		TokenType::PLUS, TokenType::MINUS,
		TokenType::STAR, TokenType::SLASH,
		TokenType::L_PARENTHESIS, TokenType::R_PARENTHESIS,
		TokenType::EQUAL
	};
	int _pos, _lengh;

	void addToken(const TokenType &type);
	void addToken(const TokenType &type, std::string text);

	char peek(int relativePosition);
	char next();

	void tokenizeNumber();
	void tokenizeOperetor();
	void tokenizeWord();
};

