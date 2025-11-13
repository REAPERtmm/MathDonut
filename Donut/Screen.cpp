#include "Screen.h"



Screen::Screen(int w, int h)
{
	mWidth = w;
	mHeight = h;
	mVirtualWidth = mWidth;
	mVirtualHeight = mHeight;
	mPositionX = 0;
	mPositionY = 0;
	mScreen = new Pixel[w * h];
}

Screen::~Screen()
{
	delete[] mScreen;
}

void Screen::SetCameraPosition(int x, int y)
{
	mPositionX = x;
	mPositionY = y;
}

void Screen::SetCameraSize(int w, int h)
{
	mVirtualWidth = w;
	mVirtualHeight = h;
}

void Screen::SetPixel(int x, int y, char c)
{
	if (x < 0 || y < 0 || x >= mWidth || y >= mHeight) {
		// Out Of Bound
		return;
	}

	mScreen[x + y * mWidth].c = c;
}

void Screen::DrawMesh(Mesh& mesh)
{
	for (int i = 0; i < mesh.GetPointCount(); ++i) {
		auto& vertex = mesh[i];
		int x = (float)mWidth * ((vertex.x - mPositionX) / (float)mVirtualWidth);
		int y = (float)mHeight * ((vertex.y - mPositionY) / (float)mVirtualHeight);

		SetPixel(x, y, 'O');
	}
}

void Screen::Display()
{
	for (int j = 0; j < mHeight; ++j) {
		for (int i = 0; i < mWidth; ++i) {
			Pixel& p = mScreen[i + mWidth * j];
			std::cout << p.fg << p.bg << p.c;
		}
		std::cout << std::endl;
	}
}
