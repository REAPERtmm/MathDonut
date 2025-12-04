#pragma once

#include "CustomOutput.h"
#include <cmath>

#define PI 3.141592635389793

enum class Axis {
	X,
	Y,
	Z
};

struct Vertex
{
	float x;
	float y;
	float z;

	void Rotate(float angle, Axis axis);
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

	void Rotate(float angle, Axis axis);

	void InitAsQuad(unsigned int size, unsigned int resolution);
	void InitAsRectangle(unsigned int width, unsigned int height, unsigned int resolution);
	void InitAsCircle(unsigned int radius, unsigned int resolution);
	void InitAsHalfCircle(unsigned int radius, unsigned int resolution);
	void InitAsTorus(unsigned int innerradius, unsigned int radius, unsigned int resolution);


	void Display();

	Vertex& operator[] (unsigned int i);
	unsigned int GetPointCount();
};

