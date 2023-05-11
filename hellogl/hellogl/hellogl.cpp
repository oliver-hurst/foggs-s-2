#include "hellogl.h"
#include "MeshLoader.h"
#include "cube.h"



HelloGL::HelloGL(int argc, char* argv[])
{
	
	InitGL(argc, argv);
	InitObjects();
	InitLighting();
	
	glutMainLoop();
}

void HelloGL::InitObjects()
{
	camera = new Camera();
	camera->eye.x = 5.0f, camera->eye.y = 5.0f, camera->eye.z = 35.0f;
	camera->centre.x = 0.0f, camera->centre.y = 0.0f, camera->centre.z = 0.0f;
	camera->up.x = 0.0f, camera->up.y = 1.0f, camera->up.z = 0.0f;
	Mesh* cubeMesh = MeshLoader::Load((char*)"cube3.txt");
	//Mesh* pyramidMesh = MeshLoader::Load((char*)"pyramid1.txt");
	texture2d* texture = new texture2d();
	texture->load((char*)"Penguins.raw", 512, 512);

	for (int i = 0; i < 500; i++)
	{
		objects[i] = new Cube(cubeMesh, texture, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000 / 10.0f));
	}

	/*for (int i = 500; i < 1000; i++)
	{
		objects[i] = new pyramid(pyramidMesh,texture, ((rand() % 400) / 10.0f) - 20.0f, ((rand() % 200) / 10.0f) - 10.0f, -(rand() % 1000 / 10.0f));
	}*/

}

void HelloGL::InitLighting()
{
	_lightposition = new Vector4();
	_lightposition->x = 0.0;
	_lightposition->y = 0.0;
	_lightposition->z = 1.0;
	_lightposition->w = 0.0;

	_lightData = new Lighting();
	_lightData->Ambient.x = 0.2;
	_lightData->Ambient.y = 0.2;
	_lightData->Ambient.z = 0.2;
	_lightData->Ambient.w = 1.0;
	_lightData->Diffuse.x = 0.8;
	_lightData->Diffuse.y = 0.8;
	_lightData->Diffuse.z = 0.8;
	_lightData->Diffuse.w = 1.0;
	_lightData->Specular.x = 0.2;
	_lightData->Specular.y = 0.2;
	_lightData->Specular.z = 0.2;
	_lightData->Specular.w = 1.0;


}

void HelloGL::InitGL(int argc, char* argv[])
{
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("simple OpenGL proggram");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glutKeyboardFunc(GLUTCallbacks::keybord);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, 800, 800);
	gluPerspective(45, 1, 1, 1000);
	
	glMatrixMode(GL_MODELVIEW);

	
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

HelloGL::~HelloGL(void)
{
	delete camera;
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (int i = 0; i < 500; i++)
	{
		objects[i]->draw();
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
	glLightfv(GL_LIGHT0, GL_AMBIENT, &(_lightData->Ambient.x));
	glLightfv(GL_LIGHT0, GL_SPECULAR, & (_lightData->Specular.x));
	glLightfv(GL_LIGHT0, GL_DIFFUSE,& (_lightData->Diffuse.x));
	glLightfv(GL_LIGHT0, GL_POSITION, &(_lightposition->x));
	glLoadIdentity();
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->centre.x, camera->centre.y, camera->centre.z, camera->up.x, camera->up.y, camera->up.z);
	for (int i = 0; i < 500; i++)
	{
		objects[i]->update();
	}
	glutPostRedisplay();

}
