#include <iostream>
#include <Windows.h>

#define CURSOR_START "\x1B[H"
#define CLEAR "\x1B[2J"
#define DEFAULT "\x1B[0m"
#define RED "\x1B[38;2;255;0;0m"
#define RESET CLEAR << CURSOR_START
#define HIDE_CUR "\x1B[?25l"
#define SHOW_CUR "\x1B[?25h"

int main(int argc, char* argv[])
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD mode;
	GetConsoleMode(hConsole, &mode);
	SetConsoleMode(hConsole, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
	
	std::cout << HIDE_CUR << RESET;

	std::cout << "Hello World" << std::endl;

	std::cout << SHOW_CUR;

	return 0;
}

