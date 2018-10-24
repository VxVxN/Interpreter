#pragma once

#include "IExpression.h"
#include "Functions.h"

class FunctionalExpression : public IExpression
{
public:
	FunctionalExpression() = default;

	FunctionalExpression(std::string name, std::list<std::unique_ptr<IExpression>> arguments);
	FunctionalExpression(std::string name);

	void addArgument(std::unique_ptr<IExpression> &argument);

	virtual std::shared_ptr<IValue> eval() override final;

private:
	std::string _name;
	std::list<std::unique_ptr<IExpression>> _arguments;
};

