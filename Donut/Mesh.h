#pragma once

#include "CustomOutput.h"
#include <cmath>

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

	unsigned int mResolution;

	void SubDivide(int vertexA, int vertexB);
public:
	Mesh();
	void Init(Vertex* vertices, unsigned int count);
	void InitAsQuad(unsigned int size, unsigned int resolution);
	void InitAsRectangle(unsigned int width, unsigned int height, unsigned int resolution);
	void InitAsCircle(unsigned int radius, unsigned int resolution);
	void InitAsHalfCircle(unsigned int radius, unsigned int resolution);
	void Display();
};

