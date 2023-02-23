#pragma once
#include<windows.h>// required for opengl on windows
#include<gl/GL.h>//open gl
#include<gl/GLU.h>// open gl utilities
#include"GL\freeglut.h" // freegult libery
#include "glutcallbacks.h"

class HelloGL
{

public:
	//constructer deffinition
	HelloGL(int argc, char* argv[]);

	//destructer
	~HelloGL(void);

	void Display();
};

