#include "UnaryExpression.h"


UnaryExpression::UnaryExpression(char operation, Expression &expr)
{
	_operation = operation;
	_expr = std::move((std::unique_ptr<Expression>)&expr);
}

double UnaryExpression::eval()
{
	switch (_operation)
	{
	case '+': return _expr->eval();
	case '-': return -_expr->eval();
	}
}