#pragma once

#include "sceneobject.h"

class Cube : public sceneobject
{
private:
	
	GLfloat _rotation;
	Vector3 _position;
	static int numvertices, numcolors, numindices;
;
	

public:
	
	Cube(Mesh* mesh, float x, float y, float z);
	~Cube();
	void draw();
	
	void update();
};
