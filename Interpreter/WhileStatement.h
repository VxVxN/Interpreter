#pragma once

#include "IStatement.h"

class WhileStatement : public IStatement
{
public:
	WhileStatement() = default;
	WhileStatement(std::unique_ptr<IExpression> &condition, std::unique_ptr<IStatement> &statement);

	virtual std::string execute() override final;

private:
	std::unique_ptr<IExpression> _condition;
	std::unique_ptr<IStatement> _statement;
};

