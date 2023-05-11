#pragma once
#include<windows.h>// required for opengl on windows
#include<gl/GL.h>//open gl
#include<gl/GLU.h>// open gl utilities
#include"GL\freeglut.h" // freegult libery





struct Vector3
{
	float x;
	float y;
	float z;


};



struct Camera
{
	Vector3 eye;
	Vector3 centre;
	Vector3 up;

};

struct Color
{
	GLfloat r, g, b;
};

struct Vertex
{
	GLfloat x, y, z;
};

struct TexCoords
{
	GLfloat u, v;
};

struct Mesh 
{
	TexCoords* TexCoords;
	Vertex* vertices;
	Vector3* Normals;
	
	GLushort* Indices;
	int VertexCount, NormalCount, IndexCount, TexCoordsCount;
	
};

struct Vector4
{
	float x, y, z, w;
};

struct Lighting
{
	Vector4 Ambient, Diffuse, Specular;
};
struct material
{
	Vector4 Ambient, Diffuse, Specular;
	GLfloat shinineness;
};