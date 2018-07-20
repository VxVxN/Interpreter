#pragma once

#include "IValue.h"

class StringValue : public IValue
{
public:
	StringValue();
	StringValue(std::string value);

	virtual double asDouble() override final;
	virtual std::string asString() override final;

private:
	std::string _value;
};

