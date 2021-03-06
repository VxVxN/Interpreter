#include "LexicalAnalyzer.h"

LexicalAnalyzer::LexicalAnalyzer(std::string input)
{
	_position = 0;
	_inputStr = input;
	_lenghStr = input.length();
}

std::list<Token> LexicalAnalyzer::tokenize()
{
	while (_position < _lenghStr) {
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

std::map<std::string, TokenType> LexicalAnalyzer::_OPERATORS = {{ "+", TokenType::PLUS },
																{ "-", TokenType::MINUS },
																{ "*", TokenType::STAR },
																{ "/", TokenType::SLASH },

																{ "(", TokenType::L_PARENTHESIS },
																{ ")", TokenType::R_PARENTHESIS },
																{ "{", TokenType::L_BRACE },
																{ "}", TokenType::R_BRACE },
																{ ";", TokenType::SEMICOLON },
																{ ",", TokenType::COMMA },

																{ "=", TokenType::EQUAL },
																{ "<", TokenType::LESS },
																{ ">", TokenType::MORE },
																{ "!=", TokenType::NOT_EQUAL },
																{ "<=", TokenType::LESS_OR_EQUAL },
																{ ">=", TokenType::MORE_OR_EQUAL },
};

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
	int position = _position + relativePosition;
	if (position >= _lenghStr) return '\0';
	return _inputStr.at(position);
}

char LexicalAnalyzer::next()
{
	_position++;
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
	char current = peek(0);
	if (current == '/') {
		if (peek(1) == '/') {
			next();
			next();
			tokenizeComment();
			return;
		}
		else if (peek(1) == '*') {
			next();
			next();
			tokenizeMultilineComment();
			return;
		}
	}
	std::string buffer("");
	while (true) {
		std::string text = buffer;
		if (!_OPERATORS.count(text + current) && !text.empty()) {
			addToken(_OPERATORS[text]);
			return;
		}
		buffer.append(&current);
		current = next();
	}
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

	if (buffer == "print")		   addToken(TokenType::PRINT);
	else if (buffer == "for")	   addToken(TokenType::FOR);
	else if (buffer == "while")	   addToken(TokenType::WHILE);
	else if (buffer == "do")	   addToken(TokenType::DO);
	else if (buffer == "break")	   addToken(TokenType::BREAK);
	else if (buffer == "continue") addToken(TokenType::CONTINUE);
	else if (buffer == "if")	   addToken(TokenType::IF);   
	else if (buffer == "else")     addToken(TokenType::ELSE);
	else if (buffer == "and")	   addToken(TokenType::LOGICAL_AND);
	else if (buffer == "or")	   addToken(TokenType::LOGICAL_OR);
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

void LexicalAnalyzer::tokenizeComment()
{
	std::string str("\n\0");
	char current = peek(0);
	while (str.find(current) && current != '\0') {
		current = next();
	}
}

void LexicalAnalyzer::tokenizeMultilineComment()
{
	char current = peek(0);
	while (true) {
		if (current == '\0') throw "LexicalAnalyzer: Missing close tag";
		if (current == '*' && peek(1) == '/') break;
		current = next();
	}
	next(); // skip *
	next(); // skip /
}