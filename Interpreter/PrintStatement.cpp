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
	std::string str = _expression->eval()->asString();
	str = str.substr(0, str.find_last_not_of('0') + 1);
	str = str.substr(0, str.find_last_not_of('.') + 1);
	return str;
}
