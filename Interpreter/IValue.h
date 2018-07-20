#pragma once

#include <string>

class IValue
{
public:
	IValue() {};

	virtual double asDouble() = 0;
	virtual std::string asString() = 0;
};

