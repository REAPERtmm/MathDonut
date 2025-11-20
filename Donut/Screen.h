#pragma once

#include "CustomOutput.h"

#include "Mesh.h"

#define CURSOR_START "\x1B[H"
#define CLEAR "\x1B[2J"
#define DEFAULT "\x1B[0m"
#define RED "\x1B[38;2;255;0;0m"
#define RESET CLEAR << CURSOR_START
#define HIDE_CUR "\x1B[?25l"
#define SHOW_CUR "\x1B[?25h"

struct Pixel
{
	char c = ' ';
	float iz = 0;
};

class Screen{

	int mWidth;
	int mHeight;

	float mCameraWidth;
	float mCameraHeight;
	float mCameraNear;

	int mPositionX;
	int mPositionY;

	Pixel* mScreen;
public:
	Screen(int w, int h);
	~Screen();

	void SetCameraPosition(int x, int y);
	void SetCameraSize(float w, float h);
	void SetCameraNear(float dist);

	void SetPixel(float x, float y, float z, char c);
	void DrawMesh(Mesh& mesh, float x, float y, float z);
	void Display();
	void Clear();
};
