#include <cstdlib>
#include <cmath>
#include <GL/glut.h>


void display(void)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);

	//glEnable(GL_ALPHA_TEST);
	//glAlphaFunc(GL_LESS, 0.5);

	glBegin(GL_TRIANGLES);
	glColor4f(1.0, 0.0, 0.0, 0.7);
	glVertex3f(0.1, 0.9, 0.0);
	glVertex3f(0.1, 0.1, 0.0);
	glVertex3f(0.7, 0.5, 0.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor4f(0.0, 1.0, 0.0, 0.3);
	glVertex3f(0.9, 0.9, 0.0);
	glVertex3f(0.3, 0.5, 0.0);
	glVertex3f(0.9, 0.1, 0.0);
	glEnd();


	glFlush();
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(700, 700);
	glutCreateWindow(argv[0]);
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 1, 0, 1, -1, 1);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

