#include "Parser.h"

Parser::Parser(std::list<Token> tokenList)
{
	_tokenList = tokenList;
	_size = tokenList.size();
	_pos = 0;
}

std::list<std::unique_ptr<Expression>> Parser::parse()
{
	std::list<std::unique_ptr<Expression>> result;
	while (!match(TokenType::END_OF_FILE)) {
		result.push_front(expression());
	}
	return result;
}

Token Parser::get(int relativePosition)
{
	int position = _pos + relativePosition;
	if (position >= _size) return _EOF;

	std::list<Token>::iterator it = std::next(_tokenList.begin(), position);
	return  *it;
}

bool Parser::match(TokenType type)
{
	Token current = get(0);
	if (type != current.getTokenType()) return false;
	_pos++;
	return true;
}

std::unique_ptr<Expression> Parser::expression()
{
	return additive();
}

std::unique_ptr<Expression> Parser::additive()
{
	std::unique_ptr<Expression> result(multiplicative());
	while (true) {
		if (match(TokenType::PLUS)) {
			std::unique_ptr<Expression> pExpr(new BinaryExpression('+', *result.release(), *multiplicative().release()));
			result = std::move(pExpr);
			continue;
		}
		if (match(TokenType::MINUS)) {
			std::unique_ptr<Expression> pExpr(new BinaryExpression('-', *result.release(), *multiplicative().release()));
			result = std::move(pExpr);
			continue;
		}
		break;
	}
	return std::move(result);
}

std::unique_ptr<Expression> Parser::multiplicative()
{
	std::unique_ptr<Expression> result(unary());
	while (true) {
		if (match(TokenType::STAR)) {
			std::unique_ptr<Expression> pExpr(new BinaryExpression('*', *result.release(), *unary().release()));
			result = std::move(pExpr);
			continue;
		}
		if (match(TokenType::SLASH)) {
			std::unique_ptr<Expression> pExpr(new BinaryExpression('/', *result.release(), *unary().release()));
			result = std::move(pExpr);
			continue;
		}
		break;
	}
	return std::move(result);
}

std::unique_ptr<Expression> Parser::unary()
{
	if (match(TokenType::MINUS)) {
		std::unique_ptr<Expression> pExpr(new UnaryExpression('-', *primary().release()));
		return std::move(pExpr);
	}
	if (match(TokenType::PLUS)) {
		return primary();
	}
	return primary();
}

std::unique_ptr<Expression> Parser::primary()
{
	Token current = get(0);
	if (match(TokenType::NUMBER)) {
		std::unique_ptr<Expression> result(new NumberExpression(atof(current.getText().c_str())));
		return std::move(result);
	}
	if (match(TokenType::L_PARENTHESIS)) {
		std::unique_ptr<Expression> result(expression().release());
		match(TokenType::R_PARENTHESIS);
		return std::move(result);
	}
	throw "Parser: Unknown expression";
}