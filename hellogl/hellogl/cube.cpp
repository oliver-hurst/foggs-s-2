#include "cube.h"

using namespace std;
#include <iostream>
#include <fstream>




Cube::Cube(Mesh* mesh, texture2d* texture,  float x, float y, float z) : sceneobject(mesh,texture)
{
	
	_rotation = 0;

	_position.x = x;
	_position.y = y;
	_position.z = z; 
}

Cube::~Cube()
{
	
}
void Cube::draw()
{
	glBindTexture(GL_TEXTURE_2D, _texture->GetID());
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);
	//glEnableClientState(GL_COLOR_ARRAY);
	glEnable(GL_NORMAL_ARRAY);
	glTexCoordPointer(2, GL_FLOAT, 0, _mesh->TexCoords);
	glVertexPointer(3, GL_FLOAT, 0, _mesh->vertices);
	glNormalPointer( GL_FLOAT, 0, _mesh->Normals);

	glPushMatrix();
	glTranslatef(_position.x, _position.y, _position.z);
	glRotatef(_rotation, 1.0f, 1.0f, 1.0f);
	
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, _mesh->Indices);
	glPopMatrix();

	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY); 
}



void Cube::update()
{
	_rotation += 1.0f;
	
	
}
