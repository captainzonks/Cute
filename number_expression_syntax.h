#pragma once

#include "expression_syntax.h"
#include "syntax_token.h"

class number_expression_syntax final : public expression_syntax
{
public:
	explicit number_expression_syntax(syntax_token number_token);

	syntax_kind get_kind() const override { return kind_; }
	syntax_token get_number_token() const { return number_token_; }
	std::vector<syntax_node> get_children() override
	{
		children_.push_back(number_token_);
		return children_;
	}

private:
	syntax_token number_token_;
};
