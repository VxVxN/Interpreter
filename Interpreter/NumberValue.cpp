#include "NumberValue.h"



NumberValue::NumberValue()
{
}

NumberValue::NumberValue(double value)
{
	_value = value;
}

double NumberValue::asDouble()
{
	return _value;
}

std::string NumberValue::asString()
{
	return std::to_string(_value);
}
