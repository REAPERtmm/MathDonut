#include <iostream>

int main()
{
	while (true)
	{
		std::cout.move(std::ios::left);
		std::cout << "O";
		std::cout.clear();
		std::cout << "|";
	}
}

