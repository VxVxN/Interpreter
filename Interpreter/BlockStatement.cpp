#include "BlockStatement.h"


void BlockStatement::add(std::unique_ptr<IStatement> &statement)
{
	_statements.push_back(std::move(statement));
}

std::string BlockStatement::execute()
{
	std::string result;
	for (auto &statement : _statements) {
		result += statement->execute();
	}
	return result;
}
