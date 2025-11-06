
#include "CustomOutput.h"
#include "Mesh.h"

#define CURSOR_START "\x1B[H"
#define CLEAR "\x1B[2J"
#define DEFAULT "\x1B[0m"
#define RED "\x1B[38;2;255;0;0m"
#define RESET CLEAR << CURSOR_START
#define HIDE_CUR "\x1B[?25l"
#define SHOW_CUR "\x1B[?25h"

int main(int argc, char* argv[])
{
	CustomOutput::Init(100, 20);
	
	CustomOutput::Get() << HIDE_CUR << CLEAR;

	//char buffer[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	//int index = 0;

	//for(int i = 0; i < 2000; ++i)
	//{
	//	CustomOutput::Get() << buffer[index];
	//	index = (++index) % 26;
	//}

	Mesh mesh;
	Vertex vertices[] = {
		{ -1, -1,  0 },
		{ -1,  1,  0 },
		{  1, -1,  0 },
		{  1,  1,  0 }
	};
	mesh.Init(vertices, 4);

	mesh.Display();

	CustomOutput::Get() << SHOW_CUR;

	return 0;
}

