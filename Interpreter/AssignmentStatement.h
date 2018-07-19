#pragma once

#include "IStatement.h"
#include "Variables.h"

class AssignmentStatement : public IStatement
{
public:
	AssignmentStatement(std::string variable, IExpression &expression);

	virtual std::string execute() override final;

private:
	std::string _variable;
	std::unique_ptr<IExpression> _expression;
};

