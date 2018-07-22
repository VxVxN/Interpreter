#pragma once

#include "IValue.h"

class StringValue : public IValue
{
public:
	StringValue() = delete;
	StringValue(std::string value);

	virtual double asNumber() override final;
	virtual std::string asString() override final;

private:
	std::string _value;
};

