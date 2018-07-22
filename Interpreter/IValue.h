#pragma once

#include <string>

class IValue
{
public:
	IValue() {};

	virtual double asNumber() = 0;
	virtual std::string asString() = 0;
};

