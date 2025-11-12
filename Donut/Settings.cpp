#include "Settings.h"
#include <string>

int Settings::ScreenWidth = DEFAULT_WIDTH;
int Settings::ScreenHeight = DEFAULT_HEIGHT;
int Settings::MeshResolution = DEFAULT_RESOLUTION;

void Settings::InitWithArgs(int argc, char* argv[])
{
	std::string cmd;
	for (int i = 0; i < argc; ++i) {
		std::string current(argv[i]);
		if (cmd == "-w") {
			ScreenWidth = std::stoi(current);
			cmd = ' ';
		} 
		else if (cmd == "-h") {
			ScreenHeight = std::stoi(current);
			cmd = ' ';
		}
		else if (cmd == "-r") {
			MeshResolution = std::stoi(current);
			cmd = ' ';
		}
		cmd = current;
	}
}
