#include "NumberValue.h"


NumberValue::NumberValue(double value)
{
	_value = value;
}

NumberValue::NumberValue(bool value)
{
	_value = value ? 1 : 0;
}

double NumberValue::asNumber()
{
	return _value;
}

std::string NumberValue::asString()
{
	return std::to_string(_value);
}
