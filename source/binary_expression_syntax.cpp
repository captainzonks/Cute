#include "binary_expression_syntax.h"
#include "syntax_token.h"

#include <algorithm>

binary_expression_syntax::binary_expression_syntax(const expression_syntax& left, syntax_token operator_token,
                                                   const expression_syntax& right):
	left_(left), operator_token_(std::move(operator_token)), right_(right)
{
	kind_ = syntax_kind::binary_expression;

	children_.push_back(left_);
	children_.push_back(operator_token_);
	children_.push_back(right_);
}
