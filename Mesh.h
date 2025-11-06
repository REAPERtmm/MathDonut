#pragma once

#include "CustomOutput.h"

struct Vertex
{
	float x;
	float y;
	float z;
};

class Mesh
{
	Vertex* mVertices;
	unsigned int mVerticesCount;

public:
	Mesh();
	void Init(Vertex* vertices, unsigned int count);
	void Display();
};

