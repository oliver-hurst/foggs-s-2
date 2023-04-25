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

struct Mesh 
{
	Vertex* vertices;
	Color* Colors;
	GLushort* Indices;
	int VertexCount, ColorCount, IndexCount;
};
