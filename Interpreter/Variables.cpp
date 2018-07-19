#include "Variables.h"

bool Variables::isExists(std::string key)
{
	return _variables.count(key);
}

double Variables::get(std::string key)
{
	if (!isExists(key)) return 0;
	return _variables[key];
}

void Variables::set(std::string key, double value)
{
	_variables.insert( std::pair<std::string, double>(key, value) );
}

///////////private/////////////////////////

std::map<std::string, double> Variables::_variables = {
	{ "PI", 3.14159265358979323846 },
	{ "E", 2.71828182845904523536 }
};