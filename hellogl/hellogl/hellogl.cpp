#include "hellogl.h"


HelloGL::HelloGL(int argc, char* argv[])
{
	rotation = 0.0f;
	camera = new Camera();
	camera->eye.x = 0.0f, camera->eye.y = 0.0f, camera->eye.z = 1.0f;
	camera->centre.x = 0.0f, camera->centre.y = 0.0f, camera->centre.z = 0.0f;
	camera->up.x = 0.0f, camera->up.y = 1.0f, camera->up.z = 0.0f;
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
	glutMainLoop();
}

HelloGL::~HelloGL(void)
{
	Camera;
}

void HelloGL::Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glTranslatef(0.0f, 0.0f, -5.0f);
	glRotatef(rotation, 2.0f, 3.0f, -1.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-0.75, 0.5);
	glVertex2f(0.75, 0.5);
	glVertex2f(0.75, -0.5);
	glVertex2f(-0.75, -0.5);
	glEnd();
	glPopMatrix();

	glFlush();
}

void HelloGL::DrawPolygon() 
{
	glBegin(GL_POLYGON); 
	{
		
		glBegin(GL_POLYGON);
		glVertex2f(-0.75, 0.5);
		glVertex2f(0.75, 0.5);
		glVertex2f(0.75, -0.5);
		glVertex2f(-0.75, -0.5);
		glEnd();
	}
}

void HelloGL:: Update() 
{
	glLoadIdentity();
	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->centre.x, camera->centre.y, camera->centre.z, camera->up.x, camera->up.y, camera->up.z);
	rotation += 0.5f;
	if (rotation >= 360.0f)
		rotation = 0.0f;
	glutPostRedisplay();

}
