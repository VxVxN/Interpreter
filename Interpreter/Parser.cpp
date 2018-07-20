#include "Parser.h"

Parser::Parser(std::list<Token> tokenList)
{
	_EOF = Token(TokenType::END_OF_FILE, "");
	_tokenList = tokenList;
	_size = tokenList.size();
	_pos = 0;
}

std::list<std::unique_ptr<IStatement>> Parser::parse()
{
	std::list<std::unique_ptr<IStatement>> result;
	while (!match(TokenType::END_OF_FILE)) {
		result.push_back(statement());
	}
	return result;
}

///////////////private//////////////////////

Token Parser::get(int relativePosition) const
{
	int position = _pos + relativePosition;
	if (position >= _size) return _EOF;

	return  *std::next(_tokenList.begin(), position);
}

bool Parser::match(const TokenType &type)
{
	Token current = get(0);
	if (type != current.getTokenType()) return false;
	_pos++;
	return true;
}

std::unique_ptr<IStatement> Parser::statement()
{
	if (match(TokenType::PRINT)) {
		std::unique_ptr<IStatement> statement(std::make_unique<PrintStatement>(*expression().release()));
		return statement;
	}
	return assignmentStatement();
}

std::unique_ptr<IStatement> Parser::assignmentStatement()
{
	Token current = get(0);
	if (match(TokenType::WORD) && get(0).getTokenType() == TokenType::EQUAL) {
		std::string variable = current.getText();
		match(TokenType::EQUAL);
		std::unique_ptr<IStatement> AssignmentStatement(std::make_unique<AssignmentStatement>(variable, *expression().release()));
		return std::move(AssignmentStatement);
	}
	throw "Parser: Unknown statement";
}

std::unique_ptr<IExpression> Parser::expression()
{
	return additive();
}

std::unique_ptr<IExpression> Parser::additive()
{
	std::unique_ptr<IExpression> result(multiplicative());
	while (true) {
		if (match(TokenType::PLUS)) {
			std::unique_ptr<IExpression> pExpr(std::make_unique<BinaryExpression>('+', *result.release(), *multiplicative().release()));
			result = std::move(pExpr);
			continue;
		}
		if (match(TokenType::MINUS)) {
			std::unique_ptr<IExpression> pExpr(std::make_unique<BinaryExpression>('-', *result.release(), *multiplicative().release()));
			result = std::move(pExpr);
			continue;
		}
		break;
	}
	return std::move(result);
}

std::unique_ptr<IExpression> Parser::multiplicative()
{
	std::unique_ptr<IExpression> result(unary());
	while (true) {
		if (match(TokenType::STAR)) {
			std::unique_ptr<IExpression> pExpr(std::make_unique<BinaryExpression>('*', *result.release(), *unary().release()));
			result = std::move(pExpr);
			continue;
		}
		if (match(TokenType::SLASH)) {
			std::unique_ptr<IExpression> pExpr(std::make_unique<BinaryExpression>('/', *result.release(), *unary().release()));
			result = std::move(pExpr);
			continue;
		}
		break;
	}
	return std::move(result);
}

std::unique_ptr<IExpression> Parser::unary()
{
	if (match(TokenType::MINUS)) {
		std::unique_ptr<IExpression> pExpr(std::make_unique<UnaryExpression>('-', *primary().release()));
		return std::move(pExpr);
	}
	if (match(TokenType::PLUS)) {
		return primary();
	}
	return primary();
}

std::unique_ptr<IExpression> Parser::primary()
{
	Token current = get(0);
	if (match(TokenType::NUMBER)) {
		std::unique_ptr<IExpression> result(std::make_unique<ValueExpression>(atof(current.getText().c_str())));
		return std::move(result);
	}
	if (match(TokenType::WORD)) {
		std::unique_ptr<IExpression> result(std::make_unique<VariableExpression>(current.getText()));
		return std::move(result);
	}
	if (match(TokenType::TEXT)) {
		std::unique_ptr<IExpression> result(std::make_unique<ValueExpression>(current.getText()));
		return std::move(result);
	}
	if (match(TokenType::L_PARENTHESIS)) {
		std::unique_ptr<IExpression> result(expression().release());
		match(TokenType::R_PARENTHESIS);
		return std::move(result);
	}
	throw "Parser: Unknown expression";
}