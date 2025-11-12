#pragma once

#define DEFAULT_WIDTH 100
#define DEFAULT_HEIGHT 20
#define DEFAULT_RESOLUTION 32

class Settings {
public:
	static int ScreenWidth;
	static int ScreenHeight;
	static int MeshResolution;

	static void InitWithArgs(int argc, char* argv[]);
};
