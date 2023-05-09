#pragma once
#include "structures.h"
#include "texture2d.h"

class sceneobject
{


protected:
	Mesh* _mesh;
	texture2d* _texture;

public:
	sceneobject(Mesh* mesh,texture2d* texture);
	virtual ~sceneobject();
	virtual void update();
	virtual void draw();

};

