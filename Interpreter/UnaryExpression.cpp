#include "UnaryExpression.h"


UnaryExpression::UnaryExpression(char operation, IExpression &expr)
{
	_operation = operation;
	_expr = std::move((std::unique_ptr<IExpression>)&expr);
}

std::shared_ptr<IValue> UnaryExpression::eval()
{
	std::shared_ptr<IValue> pValue(std::make_shared<NumberValue>(-_expr->eval()->asDouble()));
	switch (_operation)
	{
	case '+': return _expr->eval();
	case '-': return pValue;
	}
}