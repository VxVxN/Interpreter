#include "ConditionalExpression.h"



ConditionalExpression::ConditionalExpression(char operation, IExpression & expr1, IExpression & expr2)
{
	_operation = operation;
	std::shared_ptr<IExpression> pExpr1(&expr1);
	std::shared_ptr<IExpression> pExpr2(&expr2);
	_expr1 = pExpr1;
	_expr2 = pExpr2;
}

std::shared_ptr<IValue> ConditionalExpression::eval()
{
	std::shared_ptr<IValue> pExpr1(_expr1->eval());
	std::shared_ptr<IValue> pExpr2(_expr2->eval());

	IValue *value1 = &(*pExpr1);
	IValue *value2 = &(*pExpr2);

	if (dynamic_cast<StringValue*>(value1) || dynamic_cast<StringValue*>(value2)) {
		std::string string1 = value1->asString();
		std::string string2 = value2->asString();

		switch (_operation)
		{
		case '=': return std::make_shared<NumberValue>(string1 == string2);
		case '<': return std::make_shared<NumberValue>(string1.compare(string2) < 0);
		case '>': return std::make_shared<NumberValue>(string1.compare(string2) > 0);
		}
	}

	double number1 = value1->asNumber();
	double number2 = value2->asNumber();

	switch (_operation)
	{
	case '=': return std::make_shared<NumberValue>(number1 == number2);
	case '<': return std::make_shared<NumberValue>(number1 < number2);
	case '>': return std::make_shared<NumberValue>(number1 > number2);
	}
}