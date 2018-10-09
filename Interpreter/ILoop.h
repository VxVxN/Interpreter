#pragma once

#include "IStatement.h"

class ILoop : public IStatement
{
public:
	enum class Condition { BREAK, CONTINUE };

	ILoop() = default;

	std::string executeBlock(const std::string inputStatement, Condition &condition);
};

