#include <iostream>
#include <GL/glut.h>
using namespace std;
// Drawing routine.
void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glLoadIdentity();
	// Viewing transformation.
	//gluLookAt(0.0, 0.0, 15.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); // 0,0,0
	//gluLookAt(0.0, 0.0, 15.0, 0.0, 0.0, -10.0, 0.0, 1.0, 0.0); // 0 0 -10
	//gluLookAt(0.0, 0.0, 15.0, 0.0, 0.0, 20.0, 0.0, 1.0, 0.0); // 0 0 20
	//gluLookAt(0.0, 0.0, 15.0, 0.0, 0.0, 15.0, 0.0, 1.0, 0.0); // 0 0 15
	gluLookAt(0.0, 0.0, 15.0, 5.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glutWireTeapot(5.0);
	glFlush();
}

void setup(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
}

void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
}

// Main routine.
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("boxWithLookAt.cpp");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	setup();
	glutMainLoop();
}