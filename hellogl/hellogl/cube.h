#pragma once

#include "sceneobject.h"
#include "texture2d.h"

class Cube : public sceneobject
{
private:
	
	GLfloat _rotation;
	Vector3 _position;
	static int numvertices, numcolors, numindices;
;
	

public:
	
	Cube(Mesh* mesh, texture2d* texture, float x, float y, float z);
	~Cube();
	void draw();
	
	void update();
};
