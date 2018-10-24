#pragma once

#include "IFunction.h"
#include "NumberValue.h"

class SqrtFunction : public IFunction
{
public:
	SqrtFunction() = default;

	virtual std::shared_ptr<IValue> execute(std::list<std::shared_ptr<IValue>> &args) override final;
};

