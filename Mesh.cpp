#include "Mesh.h"

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
}

void Mesh::Display()
{
	std::cout << "{" << std::endl;
	for (int i = 0; i < mVerticesCount; ++i) {
		std::cout << "\t(" << mVertices[i].x << ", " << mVertices[i].y << ", " << mVertices[i].z << "), " << std::endl;
	}
	std::cout << "}" << std::endl;
}
