#pragma once
#include<windows.h>// required for opengl on windows
#include<gl/GL.h>//open gl
#include<gl/GLU.h>// open gl utilities
#include"GL\freeglut.h" // freegult libery
#include "glutcallbacks.h"
#define REFRESHRATE 16

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





class HelloGL
{

	
public:
	//constructer deffinition
	HelloGL(int argc, char* argv[]);

	//destructer
	~HelloGL(void);

	void Display();
	void DrawPolygon();
	void DrawCube();
	void keybord(unsigned char key, int x, int y);
	void DrawIndexedCube();

	void Update();
	void DrawCubeArray();



private:
	float rotation;
	static Vertex vertices[];
	static Color colors[];
	static Vertex indexedVertices[];
	static Color indexedColors[];
	static GLushort indices[];
	Camera* camera;
};

