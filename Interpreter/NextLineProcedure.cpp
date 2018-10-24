#include "NextLineProcedure.h"



std::shared_ptr<IValue> NextLineProcedure::execute(std::list<std::shared_ptr<IValue>>& args)
{
	std::shared_ptr<IValue> result = std::make_shared<StringValue>("\r\n");
	return result;
}
