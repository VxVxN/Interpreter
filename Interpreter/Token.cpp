#include "Token.h"



Token::Token(TokenType type, std::string text)
{
	_type = type;
	_text = text;
}

void Token::setTokenType(TokenType type)
{
	_type = type;
}

TokenType Token::getTokenType() const
{
	return _type;
}

void Token::setText(std::string text)
{
	_text = text;
}

std::string Token::getText() const
{
	return _text;
}