#include "EmptyFunction.h"



std::shared_ptr<IValue> EmptyFunction::execute(std::list<std::shared_ptr<IValue>>& args)
{
	std::shared_ptr<IValue> result = std::make_shared<StringValue>("");
	return result;
}
