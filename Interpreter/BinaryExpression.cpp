#include "BinaryExpression.h"



BinaryExpression::BinaryExpression(char operation, IExpression &expr1, IExpression &expr2)
{
	_operation = operation;
	std::unique_ptr<IExpression> pExpr1(&expr1);
	std::unique_ptr<IExpression> pExpr2(&expr2);
	_expr1 = std::move(pExpr1);
	_expr2 = std::move(pExpr2);
}

double BinaryExpression::eval()
{
	switch (_operation)
	{
		case '+': return _expr1->eval() + _expr2->eval();
		case '-': return _expr1->eval() - _expr2->eval();
		case '*': return _expr1->eval() * _expr2->eval();
		case '/': return _expr1->eval() / _expr2->eval();
	}
}
