#pragma once
#include "structures.h"

class sceneobject
{


protected:
	Mesh* _mesh;

public:
	sceneobject(Mesh* mesh);
	virtual ~sceneobject();
	virtual void update();
	virtual void draw();

};

