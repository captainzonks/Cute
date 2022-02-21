#pragma once

#include <string>
#include "syntax_token.h"

class lexer
{
public:
	explicit lexer(std::string text)
		: text_(std::move(text))
	{
	}

	syntax_token next_token();
	char get_current() const;
	void next();

private:
	char current_{};
	std::string text_{};
	int position_{};
};
