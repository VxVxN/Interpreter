#pragma once

#include "IValue.h"

class NumberValue : public IValue
{
public:
	NumberValue();
	NumberValue(double value);

	virtual double asDouble() override final;
	virtual std::string asString() override final;

private:
	double _value;
};

