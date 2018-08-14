#pragma once

#include "IStatement.h"

class BlockStatement : public IStatement
{
public:
	BlockStatement() = default;

	void add(std::unique_ptr<IStatement> &statement);

	virtual std::string execute() override final;

private:
	std::list<std::unique_ptr<IStatement>> _statements;
};

