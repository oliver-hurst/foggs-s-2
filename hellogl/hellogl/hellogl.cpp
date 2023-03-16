#include "hellogl.h"


Vertex HelloGL::vertices[] = { 1, 1, 1,  -1, 1, 1,  -1,-1, 1,      // v0-v1-v2 (front)
				-1,-1, 1,   1,-1, 1,   1, 1, 1,      // v2-v3-v0

				1, 1, 1,   1,-1, 1,   1,-1,-1,      // v0-v3-v4 (right)
				1,-1,-1,   1, 1,-1,   1, 1, 1,      // v4-v5-v0

				1, 1, 1,   1, 1,-1,  -1, 1,-1,      // v0-v5-v6 (top)
				-1, 1,-1,  -1, 1, 1,   1, 1, 1,      // v6-v1-v0

				-1, 1, 1,  -1, 1,-1,  -1,-1,-1,      // v1-v6-v7 (left)
				-1,-1,-1,  -1,-1, 1,  -1, 1, 1,      // v7-v2-v1

				-1,-1,-1,   1,-1,-1,   1,-1, 1,      // v7-v4-v3 (bottom)
				1,-1, 1,  -1,-1, 1,  -1,-1,-1,      // v3-v2-v7

				1,-1,-1,  -1,-1,-1,  -1, 1,-1,      // v4-v7-v6 (back)
				-1, 1,-1,   1, 1,-1,   1,-1,-1 };    // v6-v5-v4

Color HelloGL::colors[] = { 1, 1, 1,   1, 1, 0,   1, 0, 0,      // v0-v1-v2 (front)
				1, 0, 0,   1, 0, 1,   1, 1, 1,      // v2-v3-v0

				1, 1, 1,   1, 0, 1,   0, 0, 1,      // v0-v3-v4 (right)
				0, 0, 1,   0, 1, 1,   1, 1, 1,      // v4-v5-v0

				1, 1, 1,   0, 1, 1,   0, 1, 0,      // v0-v5-v6 (top)
				0, 1, 0,   1, 1, 0,   1, 1, 1,      // v6-v1-v0

				1, 1, 0,   0, 1, 0,   0, 0, 0,      // v1-v6-v7 (left)
				0, 0, 0,   1, 0, 0,   1, 1, 0,      // v7-v2-v1

				0, 0, 0,   0, 0, 1,   1, 0, 1,      // v7-v4-v3 (bottom)
				1, 0, 1,   1, 0, 0,   0, 0, 0,      // v3-v2-v7

				0, 0, 1,   0, 0, 0,   0, 1, 0,      // v4-v7-v6 (back)
				0, 1, 0,   0, 1, 1,   0, 0, 1 };// v6-v5-v4


Vertex HelloGL::indexedVertices[] = {  1, 1, 1,  -1, 1, 1,  // v0,v1,
-1,-1, 1,   1,-1, 1,   // v2,v3
1,-1,-1,   1, 1,-1,    // v4,v5
-1, 1,-1,   -1,-1,-1};// v6,v7
Color HelloGL::indexedColors[] = { 1, 1, 1,   1, 1, 0,   // v0,v1,
1, 0, 0,   1, 0, 1,   // v2,v3
0, 0, 1,   0, 1, 1,   // v4,v5
0, 1, 0,   0, 0, 0 }; //v6,v7
GLushort HelloGL::indices[] = { 0, 1, 2,  2, 3, 0,      // front
0, 3, 4,  4, 5, 0,      // right
0, 5, 6,  6, 1, 0,      // top
1, 6, 7,  7, 2, 1,      // left
7, 4, 3,  3, 2, 7,      // bottom
4, 7, 6,  6, 5, 4 };    // back


void HelloGL::DrawCubeArray() 
{
	glPushMatrix();
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 36; i++) 
	{
		glColor3fv(&colors[i].r);
		glVertex3fv(&vertices[i].x);
	}
	glEnd();
	glPopMatrix();


}

void HelloGL::DrawIndexedCube()
{
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < 36; i++) 
	{
		glColor3fv(&indexedColors[indices[i]].r);
		glVertex3fv(&indexedVertices[indices[i]].x);
	}
}
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
	DrawIndexedCube();
	//glutWireDodecahedron();
//	glBegin(GL_POLYGON);
//	glVertex2f(-0.75, 0.5);
//	glVertex2f(0.75, 0.5);
//	glVertex2f(0.75, -0.5);
//	glVertex2f(-0.75, -0.5);
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


void HelloGL::DrawCube()
{
	glBegin(GL_TRIANGLES);
	//face v0 v1 v2 
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	glColor3f(1, 1, 0 );
	glVertex3f(-1, 1, 1);
	glColor3f(1, 0, 0);
	glVertex3f(-1, -1, 1);
	//face v2 v3 v0
	glColor3f(1, 0, 0);
	glVertex3f(-1, -1, 1);
	glColor3f(1, 0, 1);
	glVertex3f(1, -1, 1);
	glColor3f(1, 1, 1 );
	glVertex3f(1, 1, 1);
	// face v0 v3 v4
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	glColor3f(1, 0, 1);
	glVertex3f(1, -1, 1);
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	// face v4-v5-v0
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	glColor3f(0, 1, 1);
	glVertex3f(1, 1, -1);
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	// face v0-v5-v6
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	glColor3f(0, 1, 1);
	glVertex3f(1, 1, -1);
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	// face v6-v1-v0
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	glColor3f(1, 1, 0);
	glVertex3f(-1, 1, 1);
	glColor3f(1, 1, 1);
	glVertex3f(1, 1, 1);
	// face  v1-v6-v7
	glColor3f(1, 1, 0);
	glVertex3f(-1, 1, 1);
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	// face v7-v2-v1
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	glColor3f(1, 0, 0);
	glVertex3f(-1, -1, 1);
	glColor3f(1, 1, 0);
	glVertex3f(-1, 1, 1);
	// face v7-v4-v3
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	glColor3f(1, 0, 1);
	glVertex3f(1, -1, 1);
	// face v3-v2-v7
	glColor3f(1, 0, 1);
	glVertex3f(1, -1, 1);
	glColor3f(1, 0, 0);
	glVertex3f(-1, -1, 1);
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);

	// face v4-v7-v6
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);
	glColor3f(0, 0, 0);
	glVertex3f(-1, -1, -1);
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	// face v6-v5-v4
	glColor3f(0, 1, 0);
	glVertex3f(-1, 1, -1);
	glColor3f(0, 1, 1);
	glVertex3f(1, 1, -1);
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, -1);

	glEnd();
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
	if (rotation >= 360.0f)
		rotation = 0.0f;
	glutPostRedisplay();

}
