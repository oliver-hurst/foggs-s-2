#pragma once

class HelloGL;

namespace GLUTCallbacks
{
	void Init(HelloGL* gl);
	void Display();
	void keybord(unsigned char key, int x, int y);

	void Timer(int preferredRefresh);

}
