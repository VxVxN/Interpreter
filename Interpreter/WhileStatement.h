#pragma once

#include "ILoop.h"

class WhileStatement : public ILoop
{
public:
	WhileStatement() = default;
	WhileStatement(std::unique_ptr<IExpression> &condition, std::unique_ptr<IStatement> &block);

	virtual std::string execute() override final;

private:
	std::unique_ptr<IExpression> _condition;
	std::unique_ptr<IStatement> _block;
};

