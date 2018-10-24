#pragma once

#include <list>

#include "IStatement.h"
#include "FunctionalExpression.h"

class FunctionStatement : public IStatement
{
public:
	FunctionStatement() = delete;
	FunctionStatement(std::string name, std::list<std::unique_ptr<IExpression>> arguments);
	FunctionStatement(std::string name);

	void addArgument(std::unique_ptr<IExpression> &argument);

	virtual std::string execute() override final;

private:
	std::string _name;
	std::list<std::unique_ptr<IExpression>> _arguments;
};

