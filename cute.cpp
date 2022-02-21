#include <iostream>
#include <string>
#include <utility>

#include "lexer.h"

int main()
{
	while (true)
	{
		std::string line;
		std::cout << "> ";
		std::getline(std::cin, line);

		if (line.empty())
		{
			break;
		}

		lexer our_lexer(line);
		while (true)
		{
			syntax_token our_token{ our_lexer.next_token() };
			if (our_token.get_kind() == syntax_kind::end_of_file_token)
			{
				break;
			}
			std::cout << "{Token Enum #}: " << static_cast<int>(our_token.get_kind()) << std::endl;
			if (our_token.get_value() != NULL)
			{
				std::cout << "{Token Value}: " << our_token.get_value() << std::endl;
			}
		}
	}
	return 0;
}
