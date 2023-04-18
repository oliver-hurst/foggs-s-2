#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL\freeglut.h"
#include "Structures.h"

class Cube
{
private:
	Mesh* _mesh;
	GLfloat _rotation;
	Vector3 _position;
	static int numvertices, numcolors, numindices;
;
	

public:
	
	Cube(Mesh* mesh, float x, float y, float z);
	~Cube();
	void Draw();
	static bool Load(char* path);

	//void Draw();
	void Update();
};
