#include "AssignmentStatement.h"



AssignmentStatement::AssignmentStatement(std::string variable, IExpression & expression)
{
	_variable = variable;
	std::unique_ptr<IExpression> pExpr(&expression);
	_expression = std::move(pExpr);
}

std::string AssignmentStatement::execute()
{
	double result = _expression->eval();
	Variables::set(_variable, result);
	return "";
}
