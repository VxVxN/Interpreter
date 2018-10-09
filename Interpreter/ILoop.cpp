#include "ILoop.h"


std::string ILoop::executeBlock(const std::string inputStatement, Condition &condition)
{
	std::string statement = inputStatement;
	int findBreak = statement.find("98 114 101 97 107"); // break to ascii
	int findConrinue = statement.find("99 111 110 116 105 110 117 101"); // conrinue to ascii
	if (findBreak != std::string::npos) {
		statement.erase(findBreak, 17);
		condition = Condition::BREAK;
		return statement;
	}
	if (findConrinue != std::string::npos) {
		statement.erase(findConrinue);
		condition = Condition::CONTINUE;
		return statement;
	}
	return statement;
}
