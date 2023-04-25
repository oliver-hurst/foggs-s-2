#pragma once
#include "sceneobject.h"
class pyramid : public sceneobject
{
private:
	static int numvertices, numcolors, numindices;
	GLfloat _rotation;
	Vector3 _position;

public:
	pyramid(Mesh* mesh, float x, float y, float z);
	~pyramid();
	void draw();
	//static bool Load(char* path);

	//void Draw();
	void update();
};

