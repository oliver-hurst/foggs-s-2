#include "sceneobject.h"

sceneobject::sceneobject(Mesh* mesh, texture2d* texture)
{
	_mesh = mesh;
	_texture = texture;
}

sceneobject::~sceneobject()
{
}

void sceneobject::update()
{
}

void sceneobject::draw()
{
}
