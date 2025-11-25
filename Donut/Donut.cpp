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
	mesh.InitAsCircle(8, Settings::MeshResolution);

	int x_pos = 2;

	while (true)
	{
		screen.Clear();
		screen.DrawMesh(mesh, x_pos, 10, 5);
		screen.Display();
		Sleep(200);
		x_pos = (x_pos + 1) % 50 + 2;
	}


	return 0;
}

