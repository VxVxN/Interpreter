#include "AssignmentStatement.h"



AssignmentStatement::AssignmentStatement(std::string variable, Expression & expression)
{
	_variable = variable;
	std::unique_ptr<Expression> pExpr(&expression);
	_expression = std::move(pExpr);
}

void AssignmentStatement::execute()
{
	double result = _expression->eval();
	Variables::set(_variable, result);
}
