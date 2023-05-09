#include "pyramid.h"

pyramid::pyramid(Mesh* mesh, texture2d* texture, float x, float y, float z) : sceneobject(mesh, nullptr)
{
	_rotation = 0;

	_position.x = x;
	_position.y = y;
	_position.z = z;
}

pyramid::~pyramid()
{
}

void pyramid::draw()
{

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, _mesh->vertices);
	glColorPointer(3, GL_FLOAT, 0, _mesh->Colors);

	glPushMatrix();
	glTranslatef(_position.x, _position.y, _position.z);
	glRotatef(_rotation, 1.0f, 1.0f, 1.0f);

	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, _mesh->Indices);
	glPopMatrix();

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void pyramid::update()
{
	_rotation = 0;
}
