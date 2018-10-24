
#include "PrintStatement.h"


PrintStatement::PrintStatement(IExpression &expression)
{
	std::unique_ptr<IExpression> pExpr(&expression);
	_expression = std::move(pExpr);
}

std::string PrintStatement::execute()
{
	auto isNumber = [](std::string token) { return std::regex_match(token, std::regex(("((\\+|-)?[[:digit:]]+)(\\.(([[:digit:]]+)?))?"))); };
	std::string str = _expression->eval()->asString();
	if (str.find('.') != std::string::npos && isNumber(str)) {
		str = str.substr(0, str.find_last_not_of('0') + 1);
		str = str.substr(0, str.find_last_not_of('.') + 1);
	}
	return str;
}
