#pragma once

#include "expression_syntax.h"
#include "syntax_token.h"

class binary_expression_syntax final : public expression_syntax
{
public:
	binary_expression_syntax(const expression_syntax& left, syntax_token operator_token, const expression_syntax& right);

	syntax_kind get_kind() const override { return kind_; }
	expression_syntax get_left() const { return left_; }
	expression_syntax get_right() const { return right_; }
	syntax_token get_operator_token() const { return operator_token_; }

	std::vector<syntax_node> get_children() override
	{
		children_.push_back(left_);
		children_.push_back(operator_token_);
		children_.push_back(right_);
		return children_;
	}

private:
	expression_syntax left_;
	syntax_token operator_token_;
	expression_syntax right_;
};
