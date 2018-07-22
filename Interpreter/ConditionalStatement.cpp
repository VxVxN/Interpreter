#include "ConditionalStatement.h"



ConditionalStatement::ConditionalStatement(IExpression &expression, IStatement &ifStatement, IStatement &elseStatement)
{
	std::unique_ptr<IExpression> pExpr(&expression);
	_expression = std::move(pExpr);
	std::unique_ptr<IStatement> pIfStatement(&ifStatement);
	_ifStatement = std::move(pIfStatement);
	std::unique_ptr<IStatement> pElseStatement(&elseStatement);
	_elseStatement = std::move(pElseStatement);
}

std::string ConditionalStatement::execute()
{
	double result = _expression->eval()->asNumber();
	if (result != 0) {
		return _ifStatement->execute();
	}
	else if (_elseStatement != NULL) {
		return _elseStatement->execute();
	}
}
