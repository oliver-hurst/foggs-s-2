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

}

