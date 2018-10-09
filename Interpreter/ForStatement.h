#pragma once

#include "ILoop.h"

class ForStatement : public ILoop
{
public:
	ForStatement() = default;
	ForStatement(std::unique_ptr<IStatement> &initialization, std::unique_ptr<IExpression> &termination,
				 std::unique_ptr<IStatement> &increment, std::unique_ptr<IStatement> &block);

	virtual std::string execute() override final;

private:
	std::unique_ptr<IStatement> _initialization;
	std::unique_ptr<IExpression> _termination;
	std::unique_ptr<IStatement> _increment;
	std::unique_ptr<IStatement> _block;
};

