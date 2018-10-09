#pragma once

#include "ILoop.h"

class DoWhileStatement : public ILoop
{
public:
	DoWhileStatement() = default;
	DoWhileStatement(std::unique_ptr<IExpression> &condition, std::unique_ptr<IStatement> &block);

	virtual std::string execute() override final;

private:
	std::unique_ptr<IExpression> _condition;
	std::unique_ptr<IStatement> _block;
};

