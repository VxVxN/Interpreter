#pragma once
#include "Expression.h"

class NumberExpression : public Expression
{
public:
	NumberExpression(double value);

	double eval() override final;

private:
	double _value;
};

