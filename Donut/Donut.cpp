#include "Settings.h"
#include "Mesh.h"
#include "Screen.h"


#define ZOOM 2


int main(int argc, char* argv[])
{
	Settings::InitWithArgs(argc, argv);

	//char buffer[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	//int index = 0;

	//for(int i = 0; i < 2000; ++i)
	//{
	//	CustomOutput::Get() << buffer[index];
	//	index = (++index) % 26;
	//}

	Screen screen(Settings::ScreenWidth, Settings::ScreenHeight);
	screen.SetCameraSize(Settings::ScreenWidth * ZOOM, Settings::ScreenHeight * ZOOM);

	Mesh mesh;
	mesh.InitAsTorus(25, 10, 256);
	//mesh.InitAsRectangle(20, 20, 128);

	int x_pos = 2;

	while (true)
	{
		screen.Clear();
		mesh.Rotate(PI / 16, Axis::Y);
		mesh.Rotate(PI / 16, Axis::Z);
		screen.DrawMesh(mesh, 0.5f * Settings::ScreenWidth * ZOOM, Settings::ScreenHeight * ZOOM, 20);
		screen.Display();
		Sleep(50);
	}


	return 0;
}

