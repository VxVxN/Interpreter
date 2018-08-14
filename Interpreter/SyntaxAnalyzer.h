#pragma once

#include <list>
#include <cstdlib>
#include <memory>

#include "Token.h"
#include "IExpression.h"
#include "ValueExpression.h"
#include "BinaryExpression.h"
#include "UnaryExpression.h"
#include "VariableExpression.h"
#include "IStatement.h"
#include "AssignmentStatement.h"
#include "PrintStatement.h"
#include "ConditionalExpression.h"
#include "ConditionalStatement.h"
#include "BlockStatement.h"

class SyntaxAnalyzer
{
public:
	SyntaxAnalyzer(std::list<Token> tokenList);

	std::unique_ptr<IStatement> parse();

private:
	int _pos;
	int _size;
	std::list<Token> _tokenList;
	Token _EOF;

	Token get(int relativePosition) const;
	bool match(const TokenType &type);

	std::unique_ptr<IStatement> block();
	std::unique_ptr<IStatement> statementOrBlock();
	std::unique_ptr<IStatement> statement();
	std::unique_ptr<IStatement> assignmentStatement();
	std::unique_ptr<IStatement> conditionalStatement();

	std::unique_ptr<IExpression> expression();
	std::unique_ptr<IExpression> logicalOr();
	std::unique_ptr<IExpression> logicalAnd();
	std::unique_ptr<IExpression> equality();
	std::unique_ptr<IExpression> conditional();
	std::unique_ptr<IExpression> additive();
	std::unique_ptr<IExpression> multiplicative();
	std::unique_ptr<IExpression> unary();
	std::unique_ptr<IExpression> primary();
};

