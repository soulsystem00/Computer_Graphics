﻿#include <GL/glut.h>
void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0); // set the bg color to a bright white
	glColor3f(0.0f, 0.0f, 0.0f); // set the drawing color to black
	glPointSize(4.0); //set the point size to 4 by 4 pixels
	glMatrixMode(GL_PROJECTION);// set up appropriate matrices- to be explained
	glLoadIdentity();// to be explained
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);// to be explained
	 
}
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT); // clear the screen
	glBegin(GL_POINTS);
	glVertex2i(100, 50); // draw some points (don't know how many)
	glVertex2i(100, 130);
	glVertex2i(150, 130);
	glEnd();
	glFlush(); // send all output to display
	 
}
void main(int argc, char** argv)
{
	glutInitWindowSize(640, 480); // set the window size
	glutInitWindowPosition(100, 150); // set the window position on the screen
	glutCreateWindow("my first attempt"); // open the screen window(with its exciting title)
	glutDisplayFunc(myDisplay); // register the redraw function
	myInit();
	glutMainLoop(); // go into a perpetual loop
}