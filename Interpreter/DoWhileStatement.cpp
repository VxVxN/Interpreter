#include "DoWhileStatement.h"


DoWhileStatement::DoWhileStatement(std::unique_ptr<IExpression>& expression, std::unique_ptr<IStatement>& statement)
{
	_condition = std::move(expression);
	_statement = std::move(statement);
}

std::string DoWhileStatement::execute()
{
	std::string result;
	do {
		std::string statement = _statement->execute();
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
	} while (_condition->eval()->asNumber() != 0);

	return result;
}
