#pragma once
#include <list>
#include <cstdlib>
#include <memory>
class Expression
{
public:
	Expression();
	virtual double eval() = 0;

};

