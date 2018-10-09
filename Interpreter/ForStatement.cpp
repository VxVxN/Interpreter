#include "ForStatement.h"


ForStatement::ForStatement(std::unique_ptr<IStatement>& initialization, std::unique_ptr<IExpression>& termination,
						   std::unique_ptr<IStatement>& increment, std::unique_ptr<IStatement>& block)
{
	_initialization = std::move(initialization);
	_termination	= std::move(termination);
	_increment		= std::move(increment);
	_block			= std::move(block);
}

std::string ForStatement::execute()
{
	std::string result;
	for (_initialization->execute(); _termination->eval()->asNumber() != 0; _increment->execute()) {
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
