#pragma once

#include "Expression.h"
#include "Variables.h"

class VariableExpression : public Expression
{
public:
	VariableExpression(std::string name);

	virtual double eval() override final;

private:
	std::string _name;
};

