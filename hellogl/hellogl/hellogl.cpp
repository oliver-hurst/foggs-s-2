#include "hellogl.h"










HelloGL::HelloGL(int argc, char* argv[])
{
	rotation = 0.0f;
	camera = new Camera();
	camera->eye.x = 0.0f, camera->eye.y = 0.0f, camera->eye.z = 1.0f;
	camera->centre.x = 0.0f, camera->centre.y = 0.0f, camera->centre.z = 0.0f;
	camera->up.x = 0.0f, camera->up.y = 1.0f, camera->up.z = 0.0f;

	cube = new Cube();
	//cube->Draw();
	GLUTCallbacks::Init(this);
	glutInit(&argc, argv);	
	glutInitWindowSize(800, 800);
	glutCreateWindow("simple OpenGL proggram");	
	glutDisplayFunc(GLUTCallbacks::Display);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, 800, 800);
	gluPerspective(45, 1, 0, 1000);
	glMatrixMode(GL_MODELVIEW);
	glutKeyboardFunc(GLUTCallbacks::keybord);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glutMainLoop();
}

HelloGL::~HelloGL(void)
{
	delete camera;
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -5.0f);
	glRotatef(rotation, 1.0f, 1.0f, 1.0f);
	cube->DrawIndexedCube();
	glEnd();
	glPopMatrix();

	glFlush();
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
	rotation += 0.5f;
	cube->Update();
	if (rotation >= 360.0f)
		rotation = 0.0f;
	glutPostRedisplay();

}
