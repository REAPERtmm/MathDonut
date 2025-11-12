#include "Screen.h"



Screen::Screen(int w, int h)
{
	mWidth = w;
	mHeight = h;
	mScreen = new Pixel[w * h];
}

Screen::~Screen()
{
	delete[] mScreen;
}

void Screen::SetPixel(int x, int y, char c)
{
	if (x < 0 || y < 0 || x >= mWidth || y >= mHeight) {
		mScreen[x + y * mWidth].c = '?';
	}
	else {
		mScreen[x + y * mWidth].c = c;
	}
}

void Screen::DrawMesh(const Mesh& mesh)
{

}

void Screen::Display()
{
	for (int j = 0; j < mHeight; ++j) {
		for (int i = 0; i < mWidth; ++i) {
			Pixel& p = mScreen[i + mHeight * j];
			std::cout << p.fg << p.bg << p.c;
		}
		std::cout << std::endl;
	}
}
