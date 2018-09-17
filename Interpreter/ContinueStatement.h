#pragma once

#include "IStatement.h"

class ContinueStatement : public IStatement
{
public:
	ContinueStatement() = default;

	virtual std::string execute() override final;
};

