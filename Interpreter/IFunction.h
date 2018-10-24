#pragma once

#include <list>

#include "IValue.h"

class IFunction
{
public:
	IFunction() = default;

	virtual std::shared_ptr<IValue> execute(std::list<std::shared_ptr<IValue>> &args) = 0;
};
