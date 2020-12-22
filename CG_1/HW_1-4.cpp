#include <GL/glut.h>
#include <math.h>
#define PI 3.141592

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);      // set the bg color to a bright white
	glMatrixMode(GL_PROJECTION);// set up appropriate matrices- to be explained 
	glLoadIdentity();// to be explained
	gluOrtho2D(0, 10, 0, 10);// to be explained
}

void drdisc(double r, double x, double y)
{
	double t = 0;
	double N = 10000;
	
	
	for (t = 0; t <= 2 * PI; t += 2 * PI / N)
	{
		glVertex2f(x + r * cos(t), y + r * sin(t));
	}
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);     // clear the screen 
	glColor3f(0, 0, 0);

	int n = 4;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			glViewport(i * (400 / n), j * (400 / n), 400 / n, 400 / n);
			glBegin(GL_LINE_STRIP);
			drdisc(10, 0, 0);
			drdisc(10, 0, 10);
			drdisc(10, 10, 0);
			drdisc(10, 10, 10);
			glEnd();

			glBegin(GL_LINE_STRIP);
			glVertex2f(0, 0);
			glVertex2f(0, 10);
			glVertex2f(10, 10);
			glVertex2f(10, 0);
			glVertex2f(0, 0);
			glEnd();
		}
	}


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
