#pragma once

#include <map>
#include <string>

#include "IFunction.h"
#include "SinFunction.h"
#include "CosFunction.h"
#include "SqrtFunction.h"
#include "NextLineProcedure.h"
#include "EmptyFunction.h"

class Functions
{
public:
	static enum class TYPE_FUNCTION { FUNCTION, PROCEDURE, ERROR };

	Functions() = delete;

	static bool isExists(std::string key, TYPE_FUNCTION type);
	static std::shared_ptr<IFunction> get(std::string key, TYPE_FUNCTION type);
	static void set(std::string key, const std::shared_ptr<IFunction> &value, TYPE_FUNCTION type);
	static void clear();

private:
	static std::map<std::string, std::shared_ptr<IFunction>> _functions;
	static std::map<std::string, std::shared_ptr<IFunction>> _procedure;
};

