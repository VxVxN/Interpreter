#pragma once

#include "IExpression.h"

class ConditionalExpression : public IExpression
{
public:
	static enum class OPERATOR {
		PLUS, MINUS, MULTIPLY, DIVIDE,
		EQUAL, LESS, MORE, LESS_OR_EQUAL, MORE_OR_EQUAL, NOT_EQUAL,
		LOGICAL_NEGATION, LOGICAL_AND, LOGICAL_OR,
	};

	ConditionalExpression(OPERATOR operation, IExpression &expr1, IExpression &expr2);

	std::shared_ptr<IValue> eval() override final;

private:
	std::shared_ptr<IExpression> _expr1, _expr2;
	OPERATOR _operation;
};

