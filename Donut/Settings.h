#pragma once

#define DEFAULT_WIDTH 100
#define DEFAULT_HEIGHT 20
#define DEFAULT_RESOLUTION 32
#define DEFAULT_BACKGROUND ' '
#define DEFAULT_MESH 'X'
#define DEFAULT_NEAR 3.33
#define DEFAULT_POSITION 9

class Settings {
public:
	static int ScreenWidth;
	static int ScreenHeight;
	static int MeshResolution;
	static char ScreenBackground;
	static char MeshForeground;
	static float ScreenNear;
	static int ScreenPosition;

	static void InitWithArgs(int argc, char* argv[]);
};
