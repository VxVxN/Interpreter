#include "WhileStatement.h"


WhileStatement::WhileStatement(std::unique_ptr<IExpression>& expression, std::unique_ptr<IStatement>& statement)
{
	_condition = std::move(expression);
	_statement = std::move(statement);
}

std::string WhileStatement::execute()
{
	std::string result;
	while (_condition->eval()->asNumber() != 0) {
		result += _statement->execute();
	}
	return result;
}
