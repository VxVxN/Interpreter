#include "FunctionalExpression.h"



FunctionalExpression::FunctionalExpression(std::string name, std::list<std::unique_ptr<IExpression>> arguments)
{
	_name = name;
	_arguments = std::move(arguments);
}

FunctionalExpression::FunctionalExpression(std::string name)
{
	_name = name;
}

void FunctionalExpression::addArgument(std::unique_ptr<IExpression> &argument)
{
	_arguments.push_back(std::move(argument));
}

std::shared_ptr<IValue> FunctionalExpression::eval()
{
	std::list<std::shared_ptr<IValue>> values(_arguments.size());
	for (std::unique_ptr<IExpression> &argument : _arguments) {
		values.push_back(argument->eval());
	}
	if (!Functions::isExists(_name, Functions::TYPE_FUNCTION::FUNCTION)) throw "Functions: Unknown function.";
	return Functions::get(_name, Functions::TYPE_FUNCTION::FUNCTION)->execute(values);
}
