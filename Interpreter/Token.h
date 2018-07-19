#pragma once

#include <String>

enum class TokenType { 
	NUMBER, PLUS, MINUS, STAR, SLASH, EQUAL,
	L_PARENTHESIS, R_PARENTHESIS, 
	WORD,
	//keyword
	PRINT,
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

