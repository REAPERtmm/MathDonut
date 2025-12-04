#include "Settings.h"
#include "Mesh.h"
#include "Screen.h"


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
	screen.SetCameraSize(100, 20);
	screen.SetCameraNear(3.33f);

	Mesh mesh;
	mesh.InitAsTorus(20, 8, Settings::MeshResolution);

	int x_pos = 2;

	while (true)
	{
		screen.Clear();
		mesh.Rotate(PI / 4, Axis::Y);
		screen.DrawMesh(mesh, 40, 40, 20);
		screen.Display();
		Sleep(50);
	}


	return 0;
}

