#include <windows.h> // use proper includes for your system
#include <math.h>
#include <gl/Gl.h>
#include <gl/Glu.h>
#include <gl/Glut.h>

// �̹����ô� �ﰢ�Լ��� ���� �׸��� ���� �ణ ������Ų �����̴�.
// �ﰢ�Լ��� ���Ͽ� �پ��� ������ �׸� �� �ִٴ� ���� �����ش�.

const int screenWidth = 400;	   // width of the screen window in pixels 
const int screenHeight = 400;	   // height of the screen window in pixels
#define PI 3.141592
#define TWOPI 2*3.14159265359

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);       // the background color is white
	glColor3f(0.0f, 0.0f, 0.0f);         // the drawing color is black 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-2.0, 2.0, -2.0, 2.0);

}
//<<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);     // clear the screen 
	double t = 0;
	unsigned int N = 200;
	glBegin(GL_LINE_STRIP);
	for (t = -PI; t <= PI; t += PI / N)
	{
		//glVertex2f(cos(t), sin(t));
		glVertex2f(cos(t), sin(t)* cos(t));
	}
	glEnd();
	glFlush();		   // send all output to display 
}
//<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
void main(int argc, char** argv)
{
	glutInit(&argc, argv);          // initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set the display mode
	glutInitWindowSize(screenWidth, screenHeight); // set the window size
	glutInitWindowPosition(100, 150); // set the window position on screen
	glutCreateWindow("Dot Plot of a Function"); // open the screen window
	glutDisplayFunc(myDisplay);     // register the redraw function
	myInit();
	glutMainLoop(); 		     // go into a perpetual loop
}