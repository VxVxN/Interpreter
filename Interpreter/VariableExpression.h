#pragma once

#include "IExpression.h"
#include "Variables.h"

class VariableExpression : public IExpression
{
public:
	VariableExpression(std::string name);

	virtual double eval() override final;

private:
	std::string _name;
};

