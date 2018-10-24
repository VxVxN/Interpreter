#pragma once

#include "IFunction.h"
#include "StringValue.h"

class NextLineProcedure : public IFunction
{
public:
	NextLineProcedure() = default;

	virtual std::shared_ptr<IValue> execute(std::list<std::shared_ptr<IValue>>& args) override final;
};

