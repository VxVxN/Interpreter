#include "WhileStatement.h"


WhileStatement::WhileStatement(std::unique_ptr<IExpression>& expression, std::unique_ptr<IStatement> &block)
{
	_condition = std::move(expression);
	_block = std::move(block);
}

std::string WhileStatement::execute()
{
	std::string result;
	while (_condition->eval()->asNumber() != 0) {
		Condition condition;
		result += executeBlock(_block->execute(), condition);
		if (condition == Condition::BREAK) {
			break;
		}
		else if (condition == Condition::CONTINUE) {
			continue;
		}
	}
	return result;
}
