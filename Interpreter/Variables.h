#pragma once

#include <map>

class Variables
{
public:
	static bool isExists(std::string key);
	static double get(std::string key);
	static void set(std::string key, double value);

private:
	static std::map<std::string, double> _variables;
};