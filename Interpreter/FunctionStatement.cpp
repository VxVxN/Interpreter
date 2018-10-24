#include "FunctionStatement.h"


FunctionStatement::FunctionStatement(std::string name, std::list<std::unique_ptr<IExpression>> arguments)
{
	_name = name;
	_arguments = std::move(arguments);
}

FunctionStatement::FunctionStatement(std::string name)
{
	_name = name;
}

void FunctionStatement::addArgument(std::unique_ptr<IExpression>& argument)
{
	_arguments.push_back(std::move(argument));
}

std::string FunctionStatement::execute()
{
	std::list<std::shared_ptr<IValue>> values(_arguments.size());
	for (std::unique_ptr<IExpression> &argument : _arguments) {
		values.push_back(argument->eval());
	}
	return Functions::get(_name, Functions::TYPE_FUNCTION::PROCEDURE)->execute(values)->asString();
}
