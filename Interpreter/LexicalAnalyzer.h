#pragma once

#include <string>
#include <list>
#include <cctype>
#include <map>

#include "Token.h"

class LexicalAnalyzer
{
public:
	LexicalAnalyzer(std::string input);

	std::list<Token> tokenList;

	std::list<Token> tokenize();
private:
	std::string _inputStr;
	const std::string OPERATOR_CHARS = "+-*/()=<>!{};,";

	static std::map<std::string, TokenType> _OPERATORS;
	int _position, _lenghStr;

	void addToken(const TokenType &type);
	void addToken(const TokenType &type, std::string text);

	char peek(int relativePosition);
	char next();

	void tokenizeNumber();
	void tokenizeOperetor();
	void tokenizeWord();
	void tokenizeText();
	void tokenizeComment();
	void tokenizeMultilineComment();
};

