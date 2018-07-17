#include "NumberExpression.h"



NumberExpression::NumberExpression(double value)
{
	_value = value;
}

double NumberExpression::eval()
{
	return _value;
}
