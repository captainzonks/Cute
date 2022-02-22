#include "parser.h"

#include <vector>

#include "binary_expression_syntax.h"
#include "number_expression_syntax.h"

parser::parser(const std::string& text): text_(text), lexer_(text)
{
	do
	{
		token_ = lexer_.next_token();
		if (token_.get_kind() != syntax_kind::whitespace_token && token_.get_kind() != syntax_kind::bad_token)
		{
			tokens_.push_back(token_);
		}
	}
	while (token_.get_kind() != syntax_kind::end_of_file_token);

	current_ = peek(0);
}

expression_syntax parser::parse_primary_expression()
{
	const syntax_token number_token{ match(syntax_kind::number_token) };
	const number_expression_syntax number_expression_syntax{number_token};
	return expression_syntax{ number_expression_syntax };
}

expression_syntax parser::parse()
{
	expression_syntax left{parse_primary_expression()};

	while (get_current().get_kind() == syntax_kind::plus_token || get_current().get_kind() == syntax_kind::minus_token)
	{
		const syntax_token operator_token{ next_token() };
		const expression_syntax right{ parse_primary_expression() };
		left = static_cast<expression_syntax>(binary_expression_syntax(left, operator_token, right));
	}

	return left;
}

syntax_token parser::peek(const int offset)
{
	const int index{position_ + offset};
	if (index >= tokens_.size())
	{
		return tokens_[tokens_.size() - 1];
	}

	return tokens_[index];
}

syntax_token parser::next_token()
{
	syntax_token current = get_current();
	position_++;
	return current;
}

syntax_token parser::match(const syntax_kind kind)
{
	syntax_token* new_token{ nullptr };

	if (peek(0).get_kind() == kind)
	{
		return next_token();
	}

	new_token = new syntax_token(kind, get_current().get_position(), "", NULL);

	return *new_token;
}
