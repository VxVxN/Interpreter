#pragma once

#include "IExpression.h"

class UnaryExpression : public IExpression
{
public:
	UnaryExpression(char operation, IExpression &expr);

	std::shared_ptr<IValue> eval() override final;

private:
	std::unique_ptr<IExpression> _expr;
	char _operation;
};

