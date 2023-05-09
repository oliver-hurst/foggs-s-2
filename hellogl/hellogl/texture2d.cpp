#include "texture2d.h"
#include <fstream>
#include <iostream>
#include<windows.h>// required for opengl on windows
#include<gl/GL.h>//open gl
#include<gl/GLU.h>// open gl utilities
#include"GL\freeglut.h" // freegult libery
using namespace std;

texture2d::texture2d()
{

}

texture2d::~texture2d()
{
}

bool texture2d::load(char* path, int width, int height)
{
	char* tempTextureData; int filesize; ifstream inFile;
	_width = width; _height = height;
	inFile.open(path, ios::binary);
	if (!inFile.good())
	{
		cerr << "cant open file" << path << endl;
	}
	inFile.seekg(0, ios::end);
	filesize = (int)inFile.tellg();
	tempTextureData = new char[filesize];
	inFile.seekg(0, ios::beg);
	inFile.read(tempTextureData, filesize);
	inFile.close();
	cout << path << "loaded" << endl;
	glGenTextures(1, &_ID);
	glBindTexture(GL_TEXTURE_2D, _ID);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, tempTextureData);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	delete[]tempTextureData;

	return true;
}
