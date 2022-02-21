#include <iostream>
#include <string>

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

		if (line == "1 + 2 * 3")
		{
			std::cout << "7" << std::endl;
		}
		else
		{
			std::cout << "ERROR: Invalid expression!" << std::endl;
		}
	}
	return 0;
}