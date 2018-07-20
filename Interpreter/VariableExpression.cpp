#include "VariableExpression.h"



VariableExpression::VariableExpression(std::string name)
{
	_name = name;
}

std::shared_ptr<IValue> VariableExpression::eval()
{
	if (!Variables::isExists(_name)) throw "VariableExpression: Variable does't exist";
	return Variables::get(_name);
}
