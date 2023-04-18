#pragma once
#include<windows.h>// required for opengl on windows
#include<gl/GL.h>//open gl
#include<gl/GLU.h>// open gl utilities
#include"GL\freeglut.h" // freegult libery
#include "glutcallbacks.h"
#include "structures.h"
#include "Cube.h"
#include "MeshLoader.h"
#define REFRESHRATE 16


class HelloGL
{

	
public:
	//constructer deffinition
	HelloGL(int argc, char* argv[]);
	void InitObjects();
	void InitGL(int argc, char* argv[]);

	//destructer
	~HelloGL(void);

	void Display();
	void keybord(unsigned char key, int x, int y);


	void Update();



private:
	static Vertex vertices[];
	
	Camera* camera;
	Cube* cube[200];
};

