#include "lexer.h"

syntax_token lexer::next_token()
{
	// <numbers>
	// + - * /
	// <whitespace>

	if (position_ >= text_.length())
	{
		return syntax_token{ syntax_kind::end_of_file_token, position_, "\0", NULL };
	}

	if (std::isdigit(get_current()))
	{
		const int start{ position_ };
		while (isdigit(get_current()))
		{
			next();
		}

		const int length{ position_ - start };
		const std::string text{ text_.substr(start, static_cast<uint64_t>(length)) };
		const int value{ std::stoi(text) };
		return syntax_token{ syntax_kind::number_token, start, text, value };
	}

	if (std::isspace(get_current()))
	{
		const int start{ position_ };
		while (isspace(get_current()))
		{
			next();
		}

		const int length{ position_ - start };
		const std::string text{ text_.substr(start, static_cast<uint64_t>(length)) };
		return syntax_token{ syntax_kind::whitespace_token, start, text, NULL };
	}

	if (get_current() == '+')
	{
		return syntax_token{ syntax_kind::plus_token, position_++, "+", NULL };
	}
	if (get_current() == '-')
	{
		return syntax_token{ syntax_kind::minus_token, position_++, "-", NULL };
	}
	if (get_current() == '*')
	{
		return syntax_token{ syntax_kind::star_token, position_++, "*", NULL };
	}
	if (get_current() == '/')
	{
		return syntax_token{ syntax_kind::slash_token, position_++, "/", NULL };
	}
	if (get_current() == '(')
	{
		return syntax_token{ syntax_kind::open_parenthesis_token, position_++, "(", NULL };
	}
	if (get_current() == ')')
	{
		return syntax_token{ syntax_kind::closed_parenthesis_token, position_++, ")", NULL };
	}

	return syntax_token{
		syntax_kind::bad_token, position_++, text_.substr(static_cast<uint64_t>(position_) - 1, 1), NULL
	};
}

char lexer::get_current() const
{
	if (position_ >= text_.length())
	{
		return '\0';
	}
	return text_[position_];
}

void lexer::next()
{
	position_++;
}
