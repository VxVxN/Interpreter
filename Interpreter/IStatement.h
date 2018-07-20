#pragma once

#include <string>

#include "IExpression.h"
#include "StringValue.h"

class IStatement
{
public:
	virtual std::string execute() = 0;
};

