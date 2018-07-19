#pragma once

#include "IExpression.h"

class BinaryExpression : public IExpression
{
public:
	BinaryExpression(char operation, IExpression &expr1, IExpression &expr2);

	double eval() override final;

private:
	std::unique_ptr<IExpression> _expr1, _expr2;
	char _operation;
};

