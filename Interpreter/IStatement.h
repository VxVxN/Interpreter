#pragma once

#include <string>

#include "IExpression.h"

class IStatement
{
public:
	virtual std::string execute() = 0;
};

