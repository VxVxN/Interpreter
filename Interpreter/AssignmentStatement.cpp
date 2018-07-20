#include "AssignmentStatement.h"



AssignmentStatement::AssignmentStatement(std::string variable, IExpression & expression)
{
	_variable = variable;
	std::unique_ptr<IExpression> pExpr(&expression);
	_expression = std::move(pExpr);
}

std::string AssignmentStatement::execute()
{
	Variables::set(_variable,  _expression->eval());
	return "";
}
