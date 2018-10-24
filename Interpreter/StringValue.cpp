#include "StringValue.h"



StringValue::StringValue(std::string value)
{
	_value = value;
}

double StringValue::asNumber()
{
	try
	{
		return atof(_value.c_str());
	}
	catch (...)
	{
		throw "StringValue: Cannot convert \"String\" to \"Number\".";
	}
}

std::string StringValue::asString()
{
	return _value;
}
