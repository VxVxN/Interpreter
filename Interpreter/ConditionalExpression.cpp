#include "ConditionalExpression.h"



ConditionalExpression::ConditionalExpression(OPERATOR operation, IExpression &expr1, IExpression &expr2)
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

	double number1, number2;

	if (dynamic_cast<StringValue*>(value1) || dynamic_cast<StringValue*>(value2)) {
		number1 = value1->asString() == value2->asString();
		number2 = 0;
	}
	else {
		number1 = value1->asNumber();
		number2 = value2->asNumber();
	}

	bool result;
	switch (_operation) {
	case OPERATOR::LESS:			result = number1 < number2; break;
	case OPERATOR::LESS_OR_EQUAL:	result = number1 <= number2; break;
	case OPERATOR::MORE:			result = number1 > number2; break;
	case OPERATOR::MORE_OR_EQUAL:	result = number1 >= number2; break;
	case OPERATOR::NOT_EQUAL:		result = number1 != number2; break;

	case OPERATOR::LOGICAL_AND:		result = (number1 != 0) && (number2 != 0); break;
	case OPERATOR::LOGICAL_OR:		result = (number1 != 0) || (number2 != 0); break;

	case OPERATOR::EQUAL:			result = number1 == number2; break;
	}
	return std::make_shared<NumberValue>(result);
}