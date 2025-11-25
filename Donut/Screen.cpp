#include "Screen.h"
#include "Settings.h"


Screen::Screen(int w, int h)
{
	mWidth = w;
	mHeight = h;
	mCameraWidth = 0;
	mCameraHeight = 0;
	mCameraNear = DEFAULT_NEAR;
	mPositionX = DEFAULT_POSITION;
	mPositionY = 0;
	mScreen = new Pixel[w * h];
	std::cout << HIDE_CUR;
	Clear();

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD dwMode;
	GetConsoleMode(hConsole, &dwMode);
	dwMode |= ENABLE_PROCESSED_OUTPUT | ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	!SetConsoleMode(hConsole, dwMode);
	SetConsoleScreenBufferSize(hConsole, { static_cast<short>(mWidth), static_cast<short>(mHeight) });
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

void Screen::SetCameraSize(float w, float h)
{
	mCameraWidth = w;
	mCameraHeight = h;
}

void Screen::SetCameraNear(float dist)
{
	mCameraNear = dist;
}

void Screen::SetPixel(float x, float y, float z, char c)
{
	if (x < 0 || y < 0 || x >= mWidth || y >= mHeight) {
		// Out Of Bound
		return;
	}

	int i = (int)x + (int)y * mWidth;
	float iz = 1 / z;
	if (mScreen[i].iz < iz) {
		mScreen[i].c = c;
		mScreen[i].iz = iz;
	}
}

void Screen::DrawMesh(Mesh& mesh, float x, float y, float z)
{
	for (int i = 0; i < mesh.GetPointCount(); ++i) {
		auto& vertex = mesh[i];

		float wx = vertex.x + x;
		float wy = vertex.y + y;
		float wz = vertex.z + z;

		float x = (mCameraNear * wx / wz); // * mCameraWidth;
		float y = (mCameraNear * wy / wz); // * mCameraHeight;
		float z = wz;

		SetPixel(x, y, z, Settings::MeshForeground);
	}
}

void Screen::Display()
{
	for (int j = 0; j < mHeight; ++j) {
		for (int i = 0; i < mWidth; ++i) {
			Pixel& p = mScreen[i + mWidth * j];
			std::cout << p.c;
		}
		std::cout << std::endl;
	}
}

void Screen::Clear()
{
	std::cout << RESET;
	for (int j = 0; j < mHeight; ++j) {
		for (int i = 0; i < mWidth; ++i) {
			Pixel& p = mScreen[i + mWidth * j];
			p.c = Settings::ScreenBackground;
			p.iz = 0;
		}
	}
}
