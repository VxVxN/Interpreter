#include "SyntaxAnalyzer.h"

SyntaxAnalyzer::SyntaxAnalyzer(std::list<Token> tokenList)
{
	_EOF = Token(TokenType::END_OF_FILE, "");
	_tokenList = tokenList;
	_size = tokenList.size();
	_pos = 0;
}

std::unique_ptr<IStatement> SyntaxAnalyzer::parse()
{
	std::unique_ptr<BlockStatement> result(std::make_unique<BlockStatement>());
	while (!match(TokenType::END_OF_FILE)) {
		result->add(statement());
	}
	return result;
}

///////////////private//////////////////////

Token SyntaxAnalyzer::get(int relativePosition) const
{
	int position = _pos + relativePosition;
	if (position >= _size) return _EOF;

	return  *std::next(_tokenList.begin(), position);
}

bool SyntaxAnalyzer::match(const TokenType &type)
{
	Token current = get(0);
	if (type != current.getTokenType()) return false;
	_pos++;
	return true;
}

std::unique_ptr<IStatement> SyntaxAnalyzer::block()
{
	std::unique_ptr<BlockStatement> block(std::make_unique<BlockStatement>());
	match(TokenType::L_BRACE);
	while (!match(TokenType::R_BRACE)) {
		block->add(statement());
	}
	return block;
}

std::unique_ptr<IStatement> SyntaxAnalyzer::statementOrBlock()
{
	if (get(0).getTokenType() == TokenType::L_BRACE) return block();
	return statement();
}

std::unique_ptr<IStatement> SyntaxAnalyzer::statement()
{
	if (match(TokenType::PRINT)) {
		std::unique_ptr<IStatement> statement(std::make_unique<PrintStatement>(*expression().release()));
		return statement;
	}
	if (match(TokenType::IF)) {
		return conditionalStatement();
	}
	if (match(TokenType::WHILE)) {
		return whileStatement();
	}
	if (match(TokenType::DO)) {
		return doWhileStatement();
	}
	if (match(TokenType::FOR)) {
		return forStatement();
	}
	if (match(TokenType::BREAK)) {
		std::unique_ptr<IStatement> statement(new BreakStatement());
		return statement;
	}
	if (match(TokenType::CONTINUE)) {
		std::unique_ptr<IStatement> statement(new ContinueStatement());
		return statement;
	}
	return assignmentStatement();
}

std::unique_ptr<IStatement> SyntaxAnalyzer::assignmentStatement()
{
	Token current = get(0);
	if (match(TokenType::WORD) && get(0).getTokenType() == TokenType::EQUAL) {
		std::string variable = current.getText();
		match(TokenType::EQUAL);
		std::unique_ptr<IStatement> AssignmentStatement(std::make_unique<AssignmentStatement>(variable, *expression().release()));
		return std::move(AssignmentStatement);
	}
	throw "SyntaxAnalyzer: Unknown statement";
}

std::unique_ptr<IStatement> SyntaxAnalyzer::conditionalStatement()
{
	std::unique_ptr<IExpression> condition(expression());
	std::unique_ptr<IStatement> ifStatement(statementOrBlock());
	std::unique_ptr<IStatement> elseStatement;
	if (match(TokenType::ELSE)) {
		elseStatement = statementOrBlock();
	}

	std::unique_ptr<IStatement> pStatement(std::make_unique<ConditionalStatement>(*condition.release(), *ifStatement.release(), *elseStatement.release()));
	return std::move(pStatement);
}

std::unique_ptr<IStatement> SyntaxAnalyzer::whileStatement()
{
	std::unique_ptr<IExpression> condition = expression();
	std::unique_ptr<IStatement> statement = statementOrBlock();
	return std::make_unique<WhileStatement>(condition, statement);
}

std::unique_ptr<IStatement> SyntaxAnalyzer::doWhileStatement()
{
	std::unique_ptr<IStatement> statement = statementOrBlock();
	match(TokenType::WHILE);
	std::unique_ptr<IExpression> condition = expression();
	return std::make_unique<DoWhileStatement>(condition, statement);
}

std::unique_ptr<IStatement> SyntaxAnalyzer::forStatement()
{
	std::unique_ptr<IStatement>	 initialization	= assignmentStatement();
	match(TokenType::SEMICOLON);
	std::unique_ptr<IExpression> termination	= expression();
	match(TokenType::SEMICOLON);
	std::unique_ptr<IStatement>	 increment		= assignmentStatement();
	std::unique_ptr<IStatement>  statement		= statementOrBlock();
	return std::make_unique<ForStatement>(initialization, termination, increment, statement);
}

std::unique_ptr<IExpression> SyntaxAnalyzer::expression()
{
	return logicalOr();
}

std::unique_ptr<IExpression> SyntaxAnalyzer::logicalOr() {
	std::unique_ptr<IExpression> result(logicalAnd());

	while (true) {
		if (match(TokenType::LOGICAL_OR)) {
			std::unique_ptr<IExpression> pExpr(std::make_unique<ConditionalExpression>(ConditionalExpression::OPERATOR::LOGICAL_OR, *result.release(), *equality().release()));
			result = std::move(pExpr);
			continue;
		}
		break;
	}

	return result;
}

std::unique_ptr<IExpression> SyntaxAnalyzer::logicalAnd() {
	std::unique_ptr<IExpression> result(equality());

	while (true) {
		if (match(TokenType::LOGICAL_AND)) {
			std::unique_ptr<IExpression> pExpr(std::make_unique<ConditionalExpression>(ConditionalExpression::OPERATOR::LOGICAL_AND, *result.release(), *equality().release()));
			result = std::move(pExpr);
			continue;
		}
		break;
	}

	return result;
}

std::unique_ptr<IExpression> SyntaxAnalyzer::equality() {
	std::unique_ptr<IExpression> result(conditional());

	if (match(TokenType::EQUAL)) {
		std::unique_ptr<IExpression> pExpr(std::make_unique<ConditionalExpression>(ConditionalExpression::OPERATOR::EQUAL, *result.release(), *conditional().release()));
		return std::move(pExpr);
	}
	if (match(TokenType::NOT_EQUAL)) {
		std::unique_ptr<IExpression> pExpr(std::make_unique<ConditionalExpression>(ConditionalExpression::OPERATOR::NOT_EQUAL, *result.release(), *conditional().release()));
		return std::move(pExpr);
	}

	return result;
}

std::unique_ptr<IExpression> SyntaxAnalyzer::conditional()
{
	std::unique_ptr<IExpression> result(additive());
	while (true) {
		if (match(TokenType::LESS_OR_EQUAL)) {
			std::unique_ptr<IExpression> pExpr(std::make_unique<ConditionalExpression>(ConditionalExpression::OPERATOR::LESS_OR_EQUAL, *result.release(), *multiplicative().release()));
			result = std::move(pExpr);
			continue;
		}
		if (match(TokenType::MORE_OR_EQUAL)) {
			std::unique_ptr<IExpression> pExpr(std::make_unique<ConditionalExpression>(ConditionalExpression::OPERATOR::MORE_OR_EQUAL, *result.release(), *multiplicative().release()));
			result = std::move(pExpr);
			continue;
		}
		if (match(TokenType::LESS)) {
			std::unique_ptr<IExpression> pExpr(std::make_unique<ConditionalExpression>(ConditionalExpression::OPERATOR::LESS, *result.release(), *multiplicative().release()));
			result = std::move(pExpr);
			continue;
		}
		if (match(TokenType::MORE)) {
			std::unique_ptr<IExpression> pExpr(std::make_unique<ConditionalExpression>(ConditionalExpression::OPERATOR::MORE_OR_EQUAL, *result.release(), *multiplicative().release()));
			result = std::move(pExpr);
			continue;
		}
		break;
	}
	return std::move(result);
}

std::unique_ptr<IExpression> SyntaxAnalyzer::additive()
{
	std::unique_ptr<IExpression> result(multiplicative());
	while (true) {
		if (match(TokenType::PLUS)) {
			std::unique_ptr<IExpression> pExpr(std::make_unique<BinaryExpression>('+', *result.release(), *multiplicative().release()));
			result = std::move(pExpr);
			continue;
		}
		if (match(TokenType::MINUS)) {
			std::unique_ptr<IExpression> pExpr(std::make_unique<BinaryExpression>('-', *result.release(), *multiplicative().release()));
			result = std::move(pExpr);
			continue;
		}
		break;
	}
	return std::move(result);
}

std::unique_ptr<IExpression> SyntaxAnalyzer::multiplicative()
{
	std::unique_ptr<IExpression> result(unary());
	while (true) {
		if (match(TokenType::STAR)) {
			std::unique_ptr<IExpression> pExpr(std::make_unique<BinaryExpression>('*', *result.release(), *unary().release()));
			result = std::move(pExpr);
			continue;
		}
		if (match(TokenType::SLASH)) {
			std::unique_ptr<IExpression> pExpr(std::make_unique<BinaryExpression>('/', *result.release(), *unary().release()));
			result = std::move(pExpr);
			continue;
		}
		break;
	}
	return std::move(result);
}

std::unique_ptr<IExpression> SyntaxAnalyzer::unary()
{
	if (match(TokenType::MINUS)) {
		std::unique_ptr<IExpression> pExpr(std::make_unique<UnaryExpression>('-', *primary().release()));
		return std::move(pExpr);
	}
	if (match(TokenType::PLUS)) {
		return primary();
	}
	return primary();
}

std::unique_ptr<IExpression> SyntaxAnalyzer::primary()
{
	Token current = get(0);
	if (match(TokenType::NUMBER)) {
		std::unique_ptr<IExpression> result(std::make_unique<ValueExpression>(atof(current.getText().c_str())));
		return std::move(result);
	}
	if (match(TokenType::WORD)) {
		std::unique_ptr<IExpression> result(std::make_unique<VariableExpression>(current.getText()));
		return std::move(result);
	}
	if (match(TokenType::TEXT)) {
		std::unique_ptr<IExpression> result(std::make_unique<ValueExpression>(current.getText()));
		return std::move(result);
	}
	if (match(TokenType::L_PARENTHESIS)) {
		std::unique_ptr<IExpression> result(expression().release());
		match(TokenType::R_PARENTHESIS);
		return std::move(result);
	}
	throw "SyntaxAnalyzer: Unknown expression";
}