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
		std::string statement = _block->execute();
		int findBreak = statement.find("98 114 101 97 107"); // break to ascii
		int findConrinue = statement.find("99 111 110 116 105 110 117 101"); // conrinue to ascii
		if (findBreak != std::string::npos) {
			statement.erase(findBreak, 17);
			result += statement;
			break; 
		}
		if (findConrinue != std::string::npos) {
			statement.erase(findConrinue);
			result += statement;
			continue;
		}
		result += statement;
	}
	return result;
}
