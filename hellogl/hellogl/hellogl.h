#pragma once
#include "glutcallbacks.h"
//#include "structures.h"
#include "sceneobject.h"
#include "Cube.h"
#include "pyramid.h"

//#include "MeshLoader.h"
#define REFRESHRATE 16


class HelloGL
{

	
public:
	//constructer deffinition
	HelloGL(int argc, char* argv[]);
	void InitObjects();
	void InitLighting();
	void InitGL(int argc, char* argv[]);

	//destructer
	~HelloGL(void);

	void Display();
	void keybord(unsigned char key, int x, int y);


	void Update();



private:
	static Vertex vertices[];
	
	Vector4* _lightposition;
	Lighting* _lightData;
	Camera* camera;
	sceneobject* objects[1000];
	
};

