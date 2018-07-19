#pragma once

#include <list>
#include <cstdlib>
#include <memory>

class Expression
{
public:
	virtual double eval() = 0;
};

