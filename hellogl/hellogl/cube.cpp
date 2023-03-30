#include "cube.h"
using namespace std;
#include <iostream>
#include <fstream>


Vertex* indexedVertices = nullptr;

Color* indexedColors = nullptr;

GLushort* indices = nullptr;


int Cube::numvertices = 0;
int Cube::numindices = 0;
int Cube::numcolors = 0;


bool Cube::Load(char*  path)
{
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
	return true;

}
Cube::Cube(float x, float y, float z)
{
	_rotation = 0;

	_position.x = x;
	_position.y = y;
	_position.z = z; 
}

Cube::~Cube()
{
	
}
void Cube::Draw()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, indexedVertices);
	glColorPointer(3, GL_FLOAT, 0, indexedColors);

	glPushMatrix();
	glRotatef(_rotation, 1.0f, 0.0f, 0.0f);
	glTranslatef(_position.x, _position.y, _position.z);
		glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, indices);
	glPopMatrix();

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}



void Cube::Update()
{
	_rotation += 0.2;
}
