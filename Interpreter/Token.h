#pragma once

#include <String>

enum class TokenType { NUMBER, PLUS, MINUS, STAR, SLASH, END_OF_FILE };

class Token
{
public:
	Token(TokenType type, std::string text);

	void setTokenType(TokenType type);
	TokenType getTokenType() const;

	void setText(std::string text);
	std::string getText() const;
private:
	TokenType _type;
	std::string _text;
};

