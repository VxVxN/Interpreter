#include "ValueExpression.h"



ValueExpression::ValueExpression(double value)
{
	_value = std::make_shared<NumberValue>(value);
}

ValueExpression::ValueExpression(std::string value)
{
	_value = std::make_shared<StringValue>(value);
}

std::shared_ptr<IValue> ValueExpression::eval()
{
	return _value;
}
