#pragma once

#include <list>
#include <cstdlib>
#include <memory>

#include "IValue.h"
#include "NumberValue.h"
#include "StringValue.h"

class IExpression
{
public:
	virtual std::shared_ptr<IValue> eval() = 0;
};

