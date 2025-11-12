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
			mVertices[y * Resolution1D + x] = {
				((float)x * width) / (float)(Resolution1D - 1),
				((float)y * height) / (float)(Resolution1D - 1),
				0
			};
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


void Mesh::Display()
{
	std::cout << "{" << std::endl;
	for (int i = 0; i < mVerticesCount; ++i) {
		std::cout << "\t(" << mVertices[i].x << ", " << mVertices[i].y << ", " << mVertices[i].z << "), " << std::endl;
	}
	std::cout << "}" << std::endl;
}
