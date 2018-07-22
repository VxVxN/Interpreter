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
		if (isdigit(current))	   tokenizeNumber();
		else if (isalpha(current)) tokenizeWord();
		else if (current == '"')   tokenizeText();
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

void LexicalAnalyzer::addToken(const TokenType &type)
{
	Token token(type, "");
	tokenList.push_back(token);
}

void LexicalAnalyzer::addToken(const TokenType &type, std::string text)
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
	while (true) {
		if (current == '.') {
			std::size_t found = buffer.find_first_of(".");
			if (found != std::string::npos) throw "LexicalAnalyzer: Invalid float number";
		}
		else if (!isdigit(current)) {
			break;
		}
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

void LexicalAnalyzer::tokenizeWord()
{
	std::string buffer;
	char current = peek(0);
	while (true) {
		if (!isalpha(current) && !isdigit(current) && (current != '_')) {
			break;
		}
		buffer.append(&current);
		current = next();
	}

	if (buffer == "print")      addToken(TokenType::PRINT);
	else if (buffer == "if")	addToken(TokenType::IF);   
	else if (buffer == "else")  addToken(TokenType::ELSE);
	else {
		addToken(TokenType::WORD, buffer);
	}
}

void LexicalAnalyzer::tokenizeText()
{
	next(); // skip "
	std::string buffer;
	char current = peek(0);
	while (true) {
		if (current == '\\') {
			current = next();
			switch (current) {
			case '"': current = next(); buffer.append("\""); continue;
			case 'n': current = next(); buffer.append("\r\n"); continue;
			case 't': current = next(); buffer.append("\t"); continue;
			}
			buffer.append(std::to_string(current));
			continue;
		}
		if (current == '"') {
			break;
		}
		buffer.append(&current);
		current = next();
	}
	next(); // skip close "

	addToken(TokenType::TEXT, buffer);
}