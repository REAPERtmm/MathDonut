#include "Mesh.h"
#include "Screen.h"


void Mesh::SubDivide(int vertexA, int vertexB)
{
	mVertices[mVerticesCount++] = {
		(mVertices[vertexA].x + mVertices[vertexB].x) * 0.5f,
		(mVertices[vertexA].y + mVertices[vertexB].y) * 0.5f,
		(mVertices[vertexA].z + mVertices[vertexB].z) * 0.5f,
	};
}

Mesh::Mesh()
{
	mVertices = nullptr;
	mVerticesCount = 0;
}

void Mesh::Init(Vertex* vertices, unsigned int count)
{
	mVertices = new Vertex[count];
	memcpy(mVertices, vertices, count * sizeof(Vertex));
	mVerticesCount = count;
	mResolution = count;
}

void Mesh::InitAsQuad(unsigned int size, unsigned int Resolution1D)
{
	mVertices = new Vertex[Resolution1D * Resolution1D];

	for (int y = 0; y < Resolution1D; ++y) {
		for (int x = 0; x < Resolution1D; ++x) {
			mVertices[y * Resolution1D + x] = {
				((float)x * size) / (float)(Resolution1D - 1),
				((float)y * size) / (float)(Resolution1D - 1),
				0
			};
		}
	}

	mVerticesCount = Resolution1D * Resolution1D;
	mResolution = Resolution1D * Resolution1D;
}

void Mesh::InitAsRectangle(unsigned int width, unsigned int height, unsigned int Resolution1D)
{
	mVertices = new Vertex[Resolution1D * Resolution1D];

	for (int y = 0; y < Resolution1D; ++y) {
		for (int x = 0; x < Resolution1D; ++x) {
			Vertex v = {
				((float)x * width) / (float)(Resolution1D - 1),
				((float)y * height) / (float)(Resolution1D - 1),
				0
			};

			mVertices[y * Resolution1D + x] = v;

			//std::cout << mVertices[y * Resolution1D + x].x << ", " << mVertices[y * Resolution1D + x].y << ", " << mVertices[y * Resolution1D + x].z << std::endl;
		}
	}

	mVerticesCount = Resolution1D * Resolution1D;
	mResolution = Resolution1D * Resolution1D;
}

void Mesh::InitAsCircle(unsigned int radius, unsigned int Resolution1D)
{
	mVertices = new Vertex[Resolution1D * Resolution1D];

	for (int y = 0; y < Resolution1D; ++y) {
		for (int x = 0; x < Resolution1D; ++x) {
			float d = x * (float)radius / (float)(Resolution1D - 1);
			float angle = (float)y * 2 *  3.1415926f / (float)(Resolution1D - 1);

			mVertices[y * Resolution1D + x] = {
				d * cos(angle),
				d * sin(angle),
				0
			};
		}
	}

	mVerticesCount = Resolution1D * Resolution1D;
	mResolution = Resolution1D * Resolution1D;
}

void Mesh::InitAsHalfCircle(unsigned int radius, unsigned int Resolution1D)
{
	mVertices = new Vertex[Resolution1D * Resolution1D];

	for (int y = 0; y < Resolution1D; ++y) {
		for (int x = 0; x < Resolution1D; ++x) {
			float d = x * (float)radius / (float)(Resolution1D - 1);
			float angle = (float)y * 3.1415926f / (float)(Resolution1D - 1);

			mVertices[y * Resolution1D + x] = {
				d * cos(angle),
				d * sin(angle),
				0
			};
		}
	}

	mVerticesCount = Resolution1D * Resolution1D;
	mResolution = Resolution1D * Resolution1D;
}

void Mesh::InitAsTorus(unsigned int innerradius, unsigned int radius, unsigned int resolution)
{
	unsigned int r1 = resolution;
	unsigned int r2 = r1 * resolution;

	mVertices = new Vertex[r2];
	mVerticesCount = r2;
	mResolution = r2;

	for (int i = 0; i < r1; ++i)
	{
		float inner_angle = 2 * PI * (float)(i - 1) / r1;
		float _inner_cos = cos(inner_angle);
		float _inner_sin = sin(inner_angle);

		for (int j = 0; j < r1; ++j) {

			float angle = 2 * PI * (float)(j - 1) / r1;
			float _cos = cos(angle);
			//float _sin = sin(angle);
			
			mVertices[i * r1 + j].x = innerradius * _inner_cos + radius * _cos * _inner_cos;
			mVertices[i * r1 + j].y = innerradius * _inner_sin + radius * _cos * _inner_sin;
			mVertices[i * r1 + j].z = radius * sin(angle);
		}

	}

}


void Mesh::Display()
{
	std::cout << "{" << std::endl;
	for (int i = 0; i < mVerticesCount; ++i) {
		std::cout << "\t(" << mVertices[i].x << ", " << mVertices[i].y << ", " << mVertices[i].z << "), " << std::endl;
	}
	std::cout << "}" << std::endl;
}

Vertex& Mesh::operator[](unsigned int i)
{
	return mVertices[i];
}

unsigned int Mesh::GetPointCount()
{
	return mVerticesCount;
}

void Mesh::Rotate(float angle, Axis axis) {

	for (uint64_t i = 0; i < mVerticesCount; ++i) {
		mVertices[i].Rotate(angle, axis);
	}
}


void Vertex::Rotate(float angle, Axis axis)
{
	float _cos = cos(angle);
	float _sin = sin(angle);

	switch (axis)
	{
	case Axis::X: {
		float _y = _cos * y - _sin * z;
		float _z = _sin * y + _cos * z;
		y = _y;
		z = _z;
		break;
	}
	case Axis::Y: {
		float _x = _cos * x - _sin * z;
		float _z = _sin * x + _cos * z;
		x = _x;
		z = _z;
		break;
	}
	case Axis::Z: {
		float _x = _cos * x - _sin * y;
		float _y = _sin * x + _cos * y;
		x = _x;
		y = _y;
		break;
	}
	default:
		break;
	}
}
