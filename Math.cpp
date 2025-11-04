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

	COORD max = GetLargestConsoleWindowSize(hConsole);
	SHORT w = (100 > max.X) ? max.X : 100;
	SHORT h = (20 > max.Y) ? max.Y : 20;

	SMALL_RECT win = { 0, 0, (SHORT)(w - 1), (SHORT)(h - 1) };
	// Enlarge buffer first (for growth), then set window.
	SetConsoleScreenBufferSize(hConsole, { w, h });
	SetConsoleWindowInfo(hConsole, TRUE, &win);

	std::cout << HIDE_CUR << CLEAR;

	char buffer[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int index = 0;

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			std::cout << buffer[index];
			index = (++index) % 27;
		}
	}

	std::cout << SHOW_CUR;

	return 0;
}

