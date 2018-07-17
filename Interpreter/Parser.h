#pragma once

#include <list>
#include <cstdlib>
#include <memory>

#include "Token.h"
#include "Expression.h"
#include "NumberExpression.h"
#include "BinaryExpression.h"
#include "UnaryExpression.h"

class Parser
{
public:
	Parser(std::list<Token> tokenList);

	std::list<std::unique_ptr<Expression>> parse();

private:
	int _pos;
	int _size;
	std::list<Token> _tokenList;
	Token _EOF = Token(TokenType::END_OF_FILE, "");

	Token get(int relativePosition);
	bool match(TokenType type);

	std::unique_ptr<Expression> expression();
	std::unique_ptr<Expression> additive();
	std::unique_ptr<Expression> multiplicative();
	std::unique_ptr<Expression> unary();
	std::unique_ptr<Expression> primary();
};

