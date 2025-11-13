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
	screen.SetCameraPosition(-100, -20);
	screen.SetCameraSize(200, 40);

	Mesh mesh;
	/*Vertex vertices[] = {
		{ -1, -1,  0 },
		{ -1,  1,  0 },
		{  1, -1,  0 },
		{  1,  1,  0 }
	};*/
	mesh.InitAsCircle(8, Settings::MeshResolution);
	//mesh.Display();

	screen.DrawMesh(mesh);

	screen.Display();

	return 0;
}

