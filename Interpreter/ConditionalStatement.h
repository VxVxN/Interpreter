#pragma once

#include "IStatement.h"

class ConditionalStatement : public IStatement
{
public:
	ConditionalStatement() = delete;
	ConditionalStatement(IExpression &expression, IStatement &ifStatement, IStatement &elseStatement);

	virtual std::string execute() override final;

private:
	std::unique_ptr<IExpression> _expression;
	std::unique_ptr<IStatement> _ifStatement;
	std::unique_ptr<IStatement> _elseStatement;
};

