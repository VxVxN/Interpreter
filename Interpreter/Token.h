#pragma once

#include <String>

enum class TokenType { NUMBER, PLUS, MINUS, STAR, SLASH, L_PARENTHESIS, R_PARENTHESIS, END_OF_FILE };

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

