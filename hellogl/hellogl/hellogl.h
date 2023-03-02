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






class HelloGL
{

	
public:
	//constructer deffinition
	HelloGL(int argc, char* argv[]);

	//destructer
	~HelloGL(void);

	void Display();
	void DrawPolygon();

	void Update();


private:
	float rotation;
	Camera* camera;
};

