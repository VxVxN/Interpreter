#pragma once

#include "IFunction.h"
#include "NumberValue.h"

class SinFunction : public IFunction
{
public:
	SinFunction() = default;

	virtual std::shared_ptr<IValue> execute(std::list<std::shared_ptr<IValue>> &args) override final;
};

