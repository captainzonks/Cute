#pragma once

#include <string>

#include "expression_syntax.h"
#include "lexer.h"

class parser
{
public:
	explicit parser(const std::string& text);

	expression_syntax parse_primary_expression();
	expression_syntax parse();

private:
	syntax_token peek(int offset);
	syntax_token next_token();
	syntax_token match(syntax_kind kind);

	syntax_token get_current() { return peek(0); }

	std::string text_;
	lexer lexer_;
	syntax_token token_;
	syntax_token current_;
	std::vector<syntax_token> tokens_{};
	int position_{};
};
