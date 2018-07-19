#pragma once

#include <list>
#include <cstdlib>
#include <memory>

class IExpression
{
public:
	virtual double eval() = 0;
};

