#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "Structures.h"

class Cube
{
private:
//	Vertex* indexedVertices;
//	Color* indexedColors ;
//	GLushort* indices;
	GLfloat _rotation;
	Vector3 _position;
	static int numvertices, numcolors, numindices;
	static bool Load(char* path);
	

public:
	
	Cube(float x, float y, float z);
	~Cube();
	void Draw();

	//void Draw();
	void Update();
};
