#include "glutcallbacks.h"
#include"hellogl.h"

namespace  GLUTCallbacks {
	namespace 
	{
		HelloGL* helloGL = nullptr;
	}

	void Init(HelloGL* gl)
	{
		helloGL = gl;
	}
	void Display() 
	{
		if (helloGL != nullptr)
		{
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

