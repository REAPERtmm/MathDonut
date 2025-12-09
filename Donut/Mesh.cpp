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

			int index = i * r1 + j;
			float angle = 2 * PI * (float)(j - 1) / r1;
			float _cos = cos(angle);
			float _sin = sin(angle);
			
			mVertices[index].x = (innerradius + radius * _cos) * _inner_cos;
			mVertices[index].y = (innerradius + radius * _cos) * _inner_sin;
			mVertices[index].z = radius * _sin;

			mVertices[index].nx = mVertices[index].x - innerradius * _inner_cos;
			mVertices[index].ny = mVertices[index].y - innerradius * _inner_sin;
			mVertices[index].nz = mVertices[index].z;

			float length = sqrt(mVertices[index].nx * mVertices[index].nx + mVertices[index].ny * mVertices[index].ny + mVertices[index].nz * mVertices[index].nz);

			mVertices[index].nx /= length;
			mVertices[index].ny /= length;
			mVertices[index].nz /= length;
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
		float _ny = _cos * ny - _sin * nz;
		float _nz = _sin * ny + _cos * nz;
		y = _y;
		z = _z;
		ny = _ny;
		nz = _nz;
		break;
	}
	case Axis::Y: {
		float _x = _cos * x - _sin * z;
		float _z = _sin * x + _cos * z;
		float _nx = _cos * nx - _sin * nz;
		float _nz = _sin * nx + _cos * nz;
		x = _x;
		z = _z;
		nx = _nx;
		nz = _nz;
		break;
	}
	case Axis::Z: {
		float _x = _cos * x - _sin * y;
		float _y = _sin * x + _cos * y;
		float _nx = _cos * nx - _sin * ny;
		float _ny = _sin * nx + _cos * ny;
		x = _x;
		y = _y;
		nx = _nx;
		ny = _ny;
		break;
	}
	default:
		break;
	}
}
