#pragma once

#include "Statement.h"
#include "Expression.h"
#include "Variables.h"

class AssignmentStatement : public Statement
{
public:
	AssignmentStatement(std::string variable, Expression &expression);

	virtual void execute() override final;

private:
	std::string _variable;
	std::unique_ptr<Expression> _expression;
};

