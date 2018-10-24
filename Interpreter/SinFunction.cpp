#include "SinFunction.h"



std::shared_ptr<IValue> SinFunction::execute(std::list<std::shared_ptr<IValue>> &args)
{
	if (args.size() == 0 || args.size() > 2) throw "SinFunction: One arg expected.";
	std::shared_ptr<IValue> result = std::make_shared<NumberValue>(sin(args.back()->asNumber()));
	return result;
}
