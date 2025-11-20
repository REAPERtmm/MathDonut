#include "Settings.h"
#include <string>

int Settings::ScreenWidth = DEFAULT_WIDTH;
int Settings::ScreenHeight = DEFAULT_HEIGHT;
int Settings::MeshResolution = DEFAULT_RESOLUTION;
char Settings::ScreenBackground = DEFAULT_BACKGROUND;
char Settings::MeshForeground = DEFAULT_MESH;
float Settings::ScreenNear = DEFAULT_NEAR;
int Settings::ScreenPosition = DEFAULT_POSITION;

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
		else if (cmd == "-b") {
			ScreenBackground = current[0];
			cmd = ' ';
		}
		else if (cmd == "-p") {
			MeshForeground = current[0];
			cmd = ' ';
		}
		else if (cmd == "-v") {
			ScreenNear = std::stof(current);
			cmd = ' ';
		}
		else if (cmd == "-s") {
			ScreenPosition = std::stoi(current);
			cmd = ' ';
		}
		cmd = current;
	}
}
