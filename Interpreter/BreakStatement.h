#pragma once

#include "IStatement.h"

class BreakStatement : public IStatement
{
public:
	BreakStatement() = default;

	virtual std::string execute() override final;
};

