#pragma once

#include <memory>

#include "Expression.h"

class BinaryExpression : public Expression
{
public:
	BinaryExpression(char operation, Expression &expr1, Expression &expr2);

	double eval() override final;

private:
	std::unique_ptr<Expression> _expr1, _expr2;
	char _operation;
};

