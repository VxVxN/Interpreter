#pragma once

#include <String>

enum class TokenType { 
	NUMBER, PLUS, MINUS, STAR, SLASH, 
	EQUAL, LESS, MORE, LESS_OR_EQUAL, MORE_OR_EQUAL, NOT_EQUAL,
	LOGICAL_NEGATION, LOGICAL_AND, LOGICAL_OR,
	L_PARENTHESIS, R_PARENTHESIS, L_BRACE, R_BRACE,
	SEMICOLON,
	WORD, TEXT,
	//keyword
	FOR, WHILE,
	IF, ELSE, PRINT,
	END_OF_FILE 
};

class Token
{
public:
	Token() {};
	Token(const TokenType &type, std::string text);

	void setTokenType(const TokenType &type);
	TokenType getTokenType() const;

	void setText(std::string text);
	std::string getText() const;
private:
	TokenType _type;
	std::string _text;
};

