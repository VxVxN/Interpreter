#pragma once

#include "IFunction.h"
#include "StringValue.h"

class EmptyFunction : public IFunction
{
public:
	EmptyFunction() = default;

	virtual std::shared_ptr<IValue> execute(std::list<std::shared_ptr<IValue>>& args) override final;
};

