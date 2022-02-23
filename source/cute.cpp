#include <iostream>
#include <string>

#include "lexer.h"
#include "parser.h"

class syntax_node;

static void pretty_print(syntax_node* node, std::string indent = "")
{
	std::cout << indent;

	switch (node->get_kind())
	{
	case syntax_kind::number_token:
		std::cout << "Number " << std::endl;
		break;
	case syntax_kind::whitespace_token:
		std::cout << "Whitespace " << std::endl;
		break;
	case syntax_kind::plus_token:
		std::cout << "Plus " << std::endl;
		break;
	case syntax_kind::minus_token:
		std::cout << "Minus " << std::endl;
		break;
	case syntax_kind::star_token:
		std::cout << "Star " << std::endl;
		break;
	case syntax_kind::slash_token:
		std::cout << "Slash " << std::endl;
		break;
	case syntax_kind::open_parenthesis_token:
		std::cout << "Open Parenthesis " << std::endl;
		break;
	case syntax_kind::closed_parenthesis_token:
		std::cout << "Close Parenthesis " << std::endl;
		break;
	case syntax_kind::bad_token:
		std::cout << "Bad " << std::endl;
		break;
	case syntax_kind::end_of_file_token:
		std::cout << "EOF " << std::endl;
		break;
	case syntax_kind::number_expression:
		std::cout << "Number Exp " << std::endl;
		break;
	case syntax_kind::binary_expression:
		std::cout << "Binary Exp " << std::endl;
		break;
	default:;
	}

	syntax_token* token_node = dynamic_cast<syntax_token*>(node);
	if (token_node && token_node->get_value() != NULL)
	{
		std::cout << " " << std::endl;
		std::cout << token_node->get_value() << std::endl;
	}

	indent += "    ";

	for (syntax_node& child : node->get_children())
	{
		pretty_print(&child, indent);
	}
}

int main()
{
	// 1 + 2 * 3
	//
	//    TREE:
	//
	//     +
	//    / \
	//   1   *
	//      / \
	//     2   3

	while (true)
	{
		std::string line;
		std::cout << "> ";
		std::getline(std::cin, line);

		if (line.empty())
		{
			break;
		}

		parser our_parser(line);
		expression_syntax expression = our_parser.parse();

		pretty_print(&expression);

		// lexer our_lexer(line);
		// while (true)
		// {
		// 	syntax_token our_token{our_lexer.next_token()};
		// 	if (our_token.get_kind() == syntax_kind::end_of_file_token)
		// 	{
		// 		break;
		// 	}
		// 	std::cout << "{Token Enum #}: " << static_cast<int>(our_token.get_kind()) << std::endl;
		// 	if (our_token.get_value() != NULL)
		// 	{
		// 		std::cout << "{Token Value}: " << our_token.get_value() << std::endl;
		// 	}
		// }
	}
	return 0;
}


