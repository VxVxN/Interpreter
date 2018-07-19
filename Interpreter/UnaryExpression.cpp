#include "UnaryExpression.h"


UnaryExpression::UnaryExpression(char operation, IExpression &expr)
{
	_operation = operation;
	_expr = std::move((std::unique_ptr<IExpression>)&expr);
}

double UnaryExpression::eval()
{
	switch (_operation)
	{
	case '+': return _expr->eval();
	case '-': return -_expr->eval();
	}
}