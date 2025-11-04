#include <iostream>

#define CURSOR_START "\x1B[H"
#define CLEAR "\x1B[2J"
#define DEFAULT "\x1B[0m"
#define RED "\x1B[38;2;255;0;0m"
#define RESET CLEAR << CURSOR_START
#define HIDE_CUR "\x1B[?25l"
#define SHOW_CUR "\x1B[?25h"

int main(int argc, char* argv[])
{
	std::cout << HIDE_CUR << "IDnqibndiqzb" << RESET << "dnqzdqz" << DEFAULT << std::endl;
	return 0;
}

