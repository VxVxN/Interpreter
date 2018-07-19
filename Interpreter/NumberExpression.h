#pragma once

#include "IExpression.h"

class NumberExpression : public IExpression
{
public:
	NumberExpression(double value);

	double eval() override final;

private:
	double _value;
};

