#pragma once

#include "IFunction.h"
#include "NumberValue.h"

class CosFunction : public IFunction
{
public:
	CosFunction() = default;

	virtual std::shared_ptr<IValue> execute(std::list<std::shared_ptr<IValue>> &args) override final;
};

