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
	mesh.InitAsQuad(4, Settings::MeshResolution);
	
	screen.DrawMesh(mesh, 2, 2, 5);

	screen.Display();

	return 0;
}

