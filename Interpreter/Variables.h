#pragma once

#include <map>

#include "IValue.h"
#include "NumberValue.h"

class Variables
{
public:
	static bool isExists(std::string key);
	static const std::shared_ptr<IValue> &get(std::string key);
	static void set(std::string key, const std::shared_ptr<IValue> &value);
	static void clear();

private:
	static std::map<std::string, std::shared_ptr<IValue>> _variables;

	static const double _PI;
	static const double _E;
};
