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

	screen.Display();

	Mesh mesh;
	/*Vertex vertices[] = {
		{ -1, -1,  0 },
		{ -1,  1,  0 },
		{  1, -1,  0 },
		{  1,  1,  0 }
	};*/
	mesh.InitAsRectangle(4, 3, Settings::MeshResolution);

	return 0;
}

