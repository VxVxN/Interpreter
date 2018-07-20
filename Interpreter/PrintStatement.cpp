#include "PrintStatement.h"


PrintStatement::PrintStatement()
{
}

PrintStatement::PrintStatement(IExpression & expression)
{
	std::unique_ptr<IExpression> pExpr(&expression);
	_expression = std::move(pExpr);
}

std::string PrintStatement::execute()
{
	return _expression->eval()->asString();
}
