#include "LexicalAnalyzer.h"

LexicalAnalyzer::LexicalAnalyzer(std::string input)
{
	_pos = 0;
	_input = input;
	_lengh = input.length();
}

std::list<Token> LexicalAnalyzer::tokenize()
{
	while (_pos < _lengh) {
		char current = peek(0);
		if (isdigit(current)) {
			tokenizeNumber();
		}
		else if (OPERATOR_CHARS.find(current) != std::string::npos) {
			tokenizeOperetor();
		}
		else {
			next();
		}
	}
	return tokenList;
}

///////////////private//////////////////////////////////

void LexicalAnalyzer::addToken(TokenType type)
{
	Token token(type, "");
	tokenList.push_back(token);
}

void LexicalAnalyzer::addToken(TokenType type, std::string text)
{
	Token token(type, text);
	tokenList.push_back(token);
}

char LexicalAnalyzer::peek(int relativePosition)
{
	int position = _pos + relativePosition;
	if (position >= _lengh) return '\0';
	return _input.at(position);
}

char LexicalAnalyzer::next()
{
	_pos++;
	return peek(0);
}

void LexicalAnalyzer::tokenizeNumber()
{
	std::string buffer;
	char current = peek(0);
	while (isdigit(current)) {
		buffer.append(&current);
		current = next();
	}
	addToken(TokenType::NUMBER, buffer);
}

void LexicalAnalyzer::tokenizeOperetor()
{
	int position = OPERATOR_CHARS.find(peek(0));
	addToken(OPERATOR_TOKENS[position]);
	next();
}