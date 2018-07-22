#pragma once

#include "IExpression.h"

class ConditionalExpression : public IExpression
{
public:
	ConditionalExpression(char operation, IExpression &expr1, IExpression &expr2);

	std::shared_ptr<IValue> eval() override final;

private:
	std::shared_ptr<IExpression> _expr1, _expr2;
	char _operation;
};

