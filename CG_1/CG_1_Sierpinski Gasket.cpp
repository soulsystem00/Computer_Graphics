#include <stdlib.h>
#include <GL/glut.h>

// Sierpinski Gasket 은 삼각형을 그리는 알고리즘이다.
// 두점의 중점과 한점간의 중점을 그리는 과정을 반복한다.
// 트리와 같은 모양이 만들어진다.
void myinit()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);			//set the background color to white
	glColor3f(0.0, 0.0, 0.0); 					//set the foreground color to black
	glPointSize(3.0);							//set the point size to 3 X 3 pixels

												//set up a world window to screen transformation
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
	glMatrixMode(GL_MODELVIEW);

}


void drawSierpinski()
{
	// define a point data type
	typedef GLfloat point2[2];

	//define the vertices of the triangle
	point2 vertices[3] = { { 0.0, 0.0 },{ 250.0, 500.0 },{ 500.0, 0.0 } };

	//define indices to be used in the loops
	int j, k;

	//function prototype for the random number generator
	int rand();

	//define an initial point at random inside the triangle
	point2 p = { 75.0, 50.0 };

	//clear the screeen
	glClear(GL_COLOR_BUFFER_BIT);

	//compute and plot 5000 new points by selecting a point
	//halfway between the initial point and the randomly
	//selected vertex.

	for (k = 0; k < 500; k++)
	{
		j = rand() % 3;		//pick a vertex at random

							//compute the point halfway between selected vertex & old point
		p[0] = (p[0] + vertices[j][0]) / 2.0;
		p[1] = (p[1] + vertices[j][1]) / 2.0;

		// plot new point 
		glBegin(GL_POINTS);
		glVertex2fv(p);
		glEnd();
	}
	glFlush();				//send all output to the display immediately
}


int main(int argc, char** argv)
{

	//initialize the OpenGL Utility Toolkit
	glutInit(&argc, argv);

	//set the display mode--a single display buffer and colors
	//specified using amounts of red, green, & blue
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	//request a screen window 500 pixels wide by 500 pixels high
	glutInitWindowSize(400, 400);

	//specify the window position 
	glutInitWindowPosition(100, 100);

	//open and display the window putting "Sierpinski Gasket" on
	//the title bar
	glutCreateWindow("Sierpinski Gasket");

	//register the drawSierpinski() function as the function to
	//activate when a redraw event occurs.
	glutDisplayFunc(drawSierpinski);

	//set up the initial state of some of OpenGL's variables
	myinit();

	//enter an unending loop waiting from events to occur
	glutMainLoop();
	return 0;
}