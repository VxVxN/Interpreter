#pragma once

#include "IStatement.h"

class DoWhileStatement : public IStatement
{
public:
	DoWhileStatement() = default;
	DoWhileStatement(std::unique_ptr<IExpression> &condition, std::unique_ptr<IStatement> &statement);

	virtual std::string execute() override final;

private:
	std::unique_ptr<IExpression> _condition;
	std::unique_ptr<IStatement> _statement;
};

