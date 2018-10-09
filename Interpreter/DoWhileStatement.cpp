#include "DoWhileStatement.h"


DoWhileStatement::DoWhileStatement(std::unique_ptr<IExpression>& expression, std::unique_ptr<IStatement>& block)
{
	_condition = std::move(expression);
	_block = std::move(block);
}

std::string DoWhileStatement::execute()
{
	std::string result;
	do {
		Condition condition;
		result += executeBlock(_block->execute(), condition);
		if (condition == Condition::BREAK) {
			break;
		}
		else if (condition == Condition::CONTINUE) {
			continue;
		}
	} while (_condition->eval()->asNumber() != 0);

	return result;
}
