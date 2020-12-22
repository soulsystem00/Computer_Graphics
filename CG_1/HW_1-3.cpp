#include <GL/glut.h>
#include <math.h>
#define PI 3.141592

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);      // set the bg color to a bright white
	glMatrixMode(GL_PROJECTION);// set up appropriate matrices- to be explained 
	glLoadIdentity();// to be explained
	gluOrtho2D(-50, 100, 0, 150);// to be explained
}

void drdisc(double r, double x, double y)
{
	double t = 0;
	double N = 10000;
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y);
	for (t = 0; t <= 2 * PI; t += 2 * PI / N)
	{
		glVertex2f(x + r * cos(t), y + r * sin(t));
	}

	glEnd();
}

void BigOval(double x, double y)
{
	double t = 0;
	double N = 1000000;
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y);
	for (t = 0; t <= 2 * PI; t += 2 * PI / N)
	{
		glVertex2f(x + 30 * cos(t), y + 20 * sin(t));
	}
	glEnd();
}

void SmallOval(double x, double y)
{
	double t = 0;
	double N = 1000000;
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y);
	for (t = 0; t <= 2 * PI; t += 2 * PI / N)
	{
		glVertex2f(x + 15 * cos(t), y + 10 * sin(t));
	}
	glEnd();
}
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);     // clear the screen 
	

	//glColor3f(1.0, 0.0, 0.0);
	//drdisc(20.0, 25.0, 75.0); // ������ ū �� ����
	//glColor3f(1.0, 1.0, 1.0); // white
	//drdisc(10.0, 25.0, 75.0); // ��� ���� �� ���߿�

	glColor3f(0, 0, 0);
	BigOval(25, 75);
	glColor3f(1, 1, 1);
	drdisc(18, 25, 75);
	glColor3f(0,0, 0);
	SmallOval(25, 75);
	glColor3f(1, 1, 1);
	drdisc(8, 25, 75);


	glEnd();
	glFlush();		                 // send all output to display 
}
void main(int argc, char** argv)
{
	glutInitWindowSize(400, 400);     // set the window size
	glutInitWindowPosition(100, 150); // set the window position on the screen
	glutCreateWindow("my first attempt"); // open the screen window(with its exciting title)
	glutDisplayFunc(myDisplay);     // register the redraw function
	myInit();
	glutMainLoop(); 		     // go into a perpetual loop
}
