#include "MeshLoader.h"

#include <iostream>
#include <fstream>

using namespace std;

namespace MeshLoader
{
	void LoadVertices(ifstream& inFile, Mesh& mesh);
	void LoadColours(ifstream& inFile, Mesh& mesh);
	void LoadIndices(ifstream& inFile, Mesh& mesh);

	void LoadVertices(ifstream& inFile, Mesh& mesh)
	{
		inFile >> mesh.VertexCount;

		if (mesh.VertexCount > 0)
		{
			mesh.Vertices = new Vertex[mesh.VertexCount];

			for (int i = 0; i < mesh.VertexCount; i++)
			{
				inFile >> mesh.Vertices[i].x;
				inFile >> mesh.Vertices[i].y;
				inFile >> mesh.Vertices[i].z;
			}
		}
	}

	void LoadColours(ifstream& inFile, Mesh& mesh)
	{
		//TODO: LOAD COLOURS
	}

	void LoadIndices(ifstream& inFile, Mesh& mesh)
	{
		//TODO: Load Indices
	}

	Mesh* MeshLoader::Load(char* path)
	{
		Mesh* mesh = new Mesh();

		ifstream inFile;

		inFile.open(path);

		if (!inFile.good())  
		{
			cerr  << "Can't open texture file " << path << endl;
			return nullptr;
		}

		//LOAD DATA USING METHODS ABOVE

		std::ifstream inFile;
	inFile.open(path);
	if (!inFile.good())
	{
		std::cerr << "cant open the file" << path << std::endl;
		return false;
	}
	inFile >> numvertices;
	indexedVertices = new Vertex[numvertices];
	for (int i = 0; i < numvertices; i++)
	{
		inFile >> indexedVertices[i].x;
		inFile >> indexedVertices[i].y;
		inFile >> indexedVertices[i].z;
	}
	inFile >> numcolors;
	indexedColors = new Color[numcolors];
	for (int i = 0; i < numcolors; i++)
	{
		inFile >> indexedColors[i].r;
		inFile >> indexedColors[i].g;
		inFile >> indexedColors[i].b;
	}
	inFile >> numindices;
	indices = new GLushort[numindices];
	for (int i = 0; i < numindices; i++)
	{
		inFile >> indices[i];

	}
	inFile.close();
		return mesh;
	}
}