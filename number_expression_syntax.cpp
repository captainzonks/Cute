#include "number_expression_syntax.h"

number_expression_syntax::number_expression_syntax(syntax_token number_token): number_token_(std::move(number_token))
{
	kind_ = syntax_kind::number_expression;

	children_.push_back(number_token_);
}
