#pragma once

#include "IStatement.h"

class PrintStatement : public IStatement
{
public:
	PrintStatement();
	PrintStatement(IExpression & expression);

	virtual std::string execute() override final;

private:
	std::unique_ptr<IExpression> _expression;

};