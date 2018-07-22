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
		return 0.0;
	}
}

std::string StringValue::asString()
{
	return _value;
}
