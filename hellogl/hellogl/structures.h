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
	 Color* Colors;
	GLushort* Indices;
	int VertexCount, ColorCount, IndexCount, TexCoordsCount;
	Vector3* normals;
};

struct Vector4
{
	float x, y, z, w;
};

struct lighting
{
	Vector4 Ambient, Diffuse, specular;
};
struct material
{
	Vector4 Ambient, Diffuse, specular;
	GLfloat shinineness;
};