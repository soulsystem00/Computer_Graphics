#include <GL/glut.h>

#define Alpha	glVertex2f(0, 5);
#define Beta	glVertex2f(0, 6);
#define Charlie glVertex2f(1, 0);
#define Delta	glVertex2f(1, 5);
#define Echo	glVertex2f(2, 1);
#define Foxtrot glVertex2f(2, 6);
#define Golf	glVertex2f(3, 1);
#define Hotel	glVertex2f(3, 6);
#define India	glVertex2f(4, 0);
#define Juliet	glVertex2f(4, 5);
#define Kilo	glVertex2f(5, 5);
#define Lima	glVertex2f(5, 6);



#define lightgreen glColor3f(0.0, 1.0, 0.0);
#define blue glColor3f(0.0, 0.0, 1.0);
#define black glColor3f(0.0,0.0,0.0);
void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);      // set the bg color to a bright white
	glMatrixMode(GL_PROJECTION);// set up appropriate matrices- to be explained 
	glLoadIdentity();// to be explained
	gluOrtho2D(-5, 10, -5, 10);// to be explained
}

void Color_Triangulation()
{
	glBegin(GL_TRIANGLES);
	blue;
	Alpha;
	Beta;
	Delta;

	lightgreen;
	Beta;
	Delta;
	Foxtrot;

	blue;
	Delta;
	Foxtrot;
	Charlie;

	lightgreen;
	Foxtrot;
	Charlie;
	Echo;

	blue;
	Charlie;
	Echo;
	India;

	lightgreen;
	Echo;
	India;
	Golf;

	blue;
	India;
	Golf;
	Juliet;

	lightgreen;
	Golf;
	Juliet;
	Hotel;

	blue;
	Juliet;
	Hotel;
	Kilo;

	lightgreen;
	Hotel;
	Kilo;
	Lima;
	glEnd();
}

void STRIP_Triangulation()
{
	glBegin(GL_TRIANGLE_STRIP);
	black;
	Alpha;
	Beta;
	Delta;
	Foxtrot; 
	Charlie;
	Echo;
	India;
	Golf;
	Juliet;
	Hotel;
	Kilo;
	Lima;
	glEnd();
}
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);     // clear the screen 

	Color_Triangulation();
	//STRIP_Triangulation();
	
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
