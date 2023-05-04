#pragma once
#include "structures.h"
class texture2d
{
private:
	GLuint _ID;
	int _width, _height;

public:
	texture2d();
	~texture2d();
	bool load(char* path, int width, int height);
	GLuint GetID() const { return _ID; }
	int GetWidth() const { return _width; }
	int GetHeight() const { return _height; }
};

