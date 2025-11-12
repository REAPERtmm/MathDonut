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
	const char* fg = DEFAULT;
	const char* bg = DEFAULT;
	char c = '.';
};

class Screen{

	int mWidth;
	int mHeight;

	Pixel* mScreen;

public:
	Screen(int w, int h);
	~Screen();

	void SetPixel(int x, int y, char c);
	void DrawMesh(const Mesh& mesh);
	void Display();
};
