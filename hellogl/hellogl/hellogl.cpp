#include "hellogl.h"



HelloGL::HelloGL(int argc, char* argv[])
{
	InitGL(int argc, char* argv[]);
	InitObjects();

	
	glutMainLoop();
}

void HelloGL::InitObjects()
{
	camera = new Camera();
	camera->eye.x = 5.0f, camera->eye.y = 5.0f, camera->eye.z = -35.0f;
	camera->centre.x = 0.0f, camera->centre.y = 0.0f, camera->centre.z = 0.0f;
	camera->up.x = 0.0f, camera->up.y = 1.0f, camera->up.z = 0.0f;
	Mesh*cubeMesh = MeshLoader::Load("cube.txt");
	for (int i = 0; i < 200; i++)
	{
		cube[i] = new Cube(cubeMesh,((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000 / 10.0f));
	}
}

void HelloGL::InitGL(int argc, char* argv[])
{
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("simple OpenGL proggram");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, 800, 800);
	gluPerspective(45, 1, 0.1, 1000);
	glMatrixMode(GL_MODELVIEW);
	glutKeyboardFunc(GLUTCallbacks::keybord);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glEnable(GL_DEPTH_TEST);
}

HelloGL::~HelloGL(void)
{
	delete camera;
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (int i = 0; i < 200; i++)
	{
		cube[i]->Draw();
	}

	glFlush();
	glutSwapBuffers();
}






void HelloGL::keybord(unsigned char key, int x, int y)
{
	// moves camera down
	if (key == 's') 
	{
		camera->eye.y += 1.0f;
		camera->centre.y += 1.0f;
	}
		
	// moves camera up
	if (key == 'w') {
		camera->eye.y -= 1.0f;
		camera->centre.y -= 1.0f;
	}
		
	// moves camera right 
	if (key == 'd') {
		camera->eye.x += 1.0f;
		camera->centre.x += 1.0f;
	}
		
	// moves camera left
	if (key == 'a') {
		camera->eye.x -= 1.0f;
		camera->centre.x -= 1.0f;
	}
		

	// moves camera in
	if (key == 'x') {
		camera->eye.z -= 1.0f;
		camera->centre.z -= 1.0f;
	}
		
	// moves camera out
	if (key == 'z') {
		camera->eye.z += 1.0f;
		camera->centre.z += 1.0f;
	}


		
}




void HelloGL:: Update() 
{
	glLoadIdentity();
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->centre.x, camera->centre.y, camera->centre.z, camera->up.x, camera->up.y, camera->up.z);
	for (int i = 0; i < 200; i++)
	{
		cube[i]->Update();
	}
	glutPostRedisplay();

}
