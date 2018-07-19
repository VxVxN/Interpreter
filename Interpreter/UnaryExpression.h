#pragma once

#include "Expression.h"

class UnaryExpression : public Expression
{
public:
	UnaryExpression(char operation, Expression &expr);

	double eval() override final;

private:
	std::unique_ptr<Expression> _expr;
	char _operation;
};

