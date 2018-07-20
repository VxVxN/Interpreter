#pragma once

#include "IExpression.h"

class ValueExpression : public IExpression
{
public:
	ValueExpression(double value);
	ValueExpression(std::string value);

	std::shared_ptr<IValue> eval() override final;

private:
	std::shared_ptr<IValue> _value;
};

