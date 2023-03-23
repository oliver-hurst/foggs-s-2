#include "glutcallbacks.h"
#include"hellogl.h"

namespace  GLUTCallbacks {
	namespace 
	{
		HelloGL* helloGL = nullptr;
		//glEnable(GL_DEPTH_TEST); 
	}

	void Init(HelloGL* gl)
	{
		helloGL = gl;
	}
	void Display() 
	{
		if (helloGL != nullptr)
		{
			//glutInitDisplayMode(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			helloGL->Display();
		}
	}
	void keybord(unsigned char key, int x, int y)
	{
		helloGL->keybord(key, x, y);
	}
	void Timer(int preferredRefresh)
	{
		helloGL->Update();
		glutTimerFunc(preferredRefresh, GLUTCallbacks::Timer, preferredRefresh);
	}
	
}

