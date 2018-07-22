#pragma once

#include "IValue.h"

class NumberValue : public IValue
{
public:
	NumberValue() = delete;
	NumberValue(double value);
	NumberValue(bool value);

	virtual double asNumber() override final;
	virtual std::string asString() override final;

private:
	double _value;
};

