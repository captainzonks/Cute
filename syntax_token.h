#pragma once

#include <string>

enum class syntax_kind : int
{
	number_token,
	whitespace_token,
	plus_token,
	minus_token,
	star_token,
	slash_token,
	open_parenthesis_token,
	closed_parenthesis_token,
	bad_token,
	end_of_file_token
};

class syntax_token
{
public:
	syntax_token(const syntax_kind syntax_kind, const int start, std::string text, const int value) : kind_(syntax_kind),
		start_(start), value_(value), text_(
			std::move(text))
	{
	}

	syntax_kind get_kind() const { return kind_; }
	int get_start() const { return start_; }
	int get_position() const { return position_; }
	int get_value() const { return value_; }
	std::string get_text() const { return text_; }

private:
	syntax_kind kind_;
	int start_{};
	int position_{};
	int value_{};
	std::string text_;
};
