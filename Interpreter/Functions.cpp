#include "Functions.h"



bool Functions::isExists(std::string key, TYPE_FUNCTION type)
{
	if (TYPE_FUNCTION::FUNCTION == type) {
		return _functions.count(key);
	}
	if (TYPE_FUNCTION::PROCEDURE == type) {
		return _procedure.count(key);
	}
}

std::shared_ptr<IFunction> Functions::get(std::string key, TYPE_FUNCTION type)
{
	if (TYPE_FUNCTION::FUNCTION == type) {

		if (!Functions::isExists(key, Functions::TYPE_FUNCTION::FUNCTION)) throw "Functions: Unknown function.";
		return _functions[key];
	}
	if (TYPE_FUNCTION::PROCEDURE == type) {
		std::shared_ptr<IFunction> result = std::make_shared<EmptyFunction>();
		if (Functions::isExists(key, Functions::TYPE_FUNCTION::FUNCTION)) return result;
		if (!Functions::isExists(key, Functions::TYPE_FUNCTION::PROCEDURE)) throw "Functions: Unknown procedure.";
		return _procedure[key];
	}
}

void Functions::set(std::string key, const std::shared_ptr<IFunction> &value, TYPE_FUNCTION type)
{
	if (TYPE_FUNCTION::FUNCTION == type) {
		//if (isExists(key, TYPE_FUNCTION::FUNCTION)) throw "Functions: Function already exists.";
		_functions.insert(std::pair<std::string, std::shared_ptr<IFunction>>(key, value));
	}
	if (TYPE_FUNCTION::PROCEDURE == type) {
		//if (isExists(key, TYPE_FUNCTION::PROCEDURE)) throw "Functions: Procedure already exists.";
		_procedure.insert(std::pair<std::string, std::shared_ptr<IFunction>>(key, value));
	}
}

void Functions::clear()
{
	_functions.clear();
	Functions::_functions = {
		{ "sin", std::make_shared<SinFunction>() },
		{ "cos", std::make_shared<CosFunction>() },
		{ "sqrt", std::make_shared<SqrtFunction>() }
	};
	Functions::_procedure = {
		{ "next_line", std::make_shared<NextLineProcedure>() }
	};
}

///////////private/////////////////////////

std::map<std::string, std::shared_ptr<IFunction>> Functions::_functions = {
	{ "sin", std::make_shared<SinFunction>() },
	{ "cos", std::make_shared<CosFunction>() },
	{ "sqrt", std::make_shared<SqrtFunction>() }
};

std::map<std::string, std::shared_ptr<IFunction>> Functions::_procedure = {
	{ "next_line", std::make_shared<NextLineProcedure>() }
};