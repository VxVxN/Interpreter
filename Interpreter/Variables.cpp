#include "Variables.h"

bool Variables::isExists(std::string key)
{
	return _variables.count(key);
}

const std::shared_ptr<IValue> &Variables::get(std::string key)
{
	if (!isExists(key)) return std::make_shared<NumberValue>(0.0);
	return _variables[key];
}

void Variables::set(std::string key, const std::shared_ptr<IValue> &value)
{
	if (isExists(key)) _variables.erase(key);
	_variables.insert( std::pair<std::string, std::shared_ptr<IValue>>(key, value) );
}

void Variables::clear()
{
	_variables.clear();
	Variables::_variables = {
		{ "PI", std::make_shared<NumberValue>(_PI) },
		{ "E", std::make_shared<NumberValue>(_E) }
	};
}

///////////private/////////////////////////

//std::map<std::string, std::shared_ptr<IValue>> Variables::_variables = {};
std::map<std::string, std::shared_ptr<IValue>> Variables::_variables = {
	{ "PI", std::make_shared<NumberValue>(_PI) },
	{ "E", std::make_shared<NumberValue>(_E) }
};

const double Variables::_PI = 3.14159265358979323846;

const double Variables::_E = 2.71828182845904523536;