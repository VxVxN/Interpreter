#include "BinaryExpression.h"



BinaryExpression::BinaryExpression(char operation, IExpression &expr1, IExpression &expr2)
{
	_operation = operation;
	std::shared_ptr<IExpression> pExpr1(&expr1);
	std::shared_ptr<IExpression> pExpr2(&expr2);
	_expr1 = pExpr1;
	_expr2 = pExpr2;
}

std::shared_ptr<IValue> BinaryExpression::eval()
{
	std::shared_ptr<IValue> pExpr1(_expr1->eval());
	std::shared_ptr<IValue> pExpr2(_expr2->eval());

	IValue *value1 = &(*pExpr1);
	IValue *value2 = &(*pExpr2);
	
	if (dynamic_cast<StringValue*>(value1) || dynamic_cast<StringValue*>(value2)) {
		std::string string1 = value1->asString();
		std::string string2 = value2->asString();

		// убираем лишний нули у строк
		auto removeZeros = [](std::string &str) { str = str.substr(0, str.find_last_not_of('0') + 1);
												  str = str.substr(0, str.find_last_not_of('.') + 1); };

		removeZeros(string1);
		removeZeros(string2);

		switch (_operation)
		{
		case '+': return std::make_shared<StringValue>(string1 + string2);
		}
	}

	double expr1 = value1->asDouble();
	double expr2 = value2->asDouble();

	switch (_operation)
	{
	case '+': return std::make_shared<NumberValue>(expr1 + expr2);
	case '-': return std::make_shared<NumberValue>(expr1 - expr2);
	case '*': return std::make_shared<NumberValue>(expr1 * expr2);
	case '/': return std::make_shared<NumberValue>(expr1 / expr2);
	}
}
