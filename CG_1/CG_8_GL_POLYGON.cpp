#include <GL/glut.h>

// GL_POLYGON을 사용하면 여려개의 Vertex를 이용하여
// 보다 복잡한 도형을 그릴 수가 있다. 

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);      // set the bg color to a bright white
	glMatrixMode(GL_PROJECTION);// set up appropriate matrices- to be explained 
	glLoadIdentity();// to be explained
	gluOrtho2D(0.0, 200.0, 0.0, 200.0);// to be explained
}
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);     // clear the screen 
	glColor3f(0.6, 0.6, 0.6);
	glBegin(GL_POLYGON);
	glVertex2i(10, 10);
	glVertex2i(10, 60);
	glVertex2i(50, 60);
	glVertex2i(70, 30);
	glVertex2i(80, 10);
	glEnd();
	glFlush();                 // send all output to display 
}
void main(int argc, char** argv)
{
	glutInitWindowSize(400, 400);     // set the window size
	glutInitWindowPosition(100, 150); // set the window position on the screen
	glutCreateWindow("my first attempt"); // open the screen window(with its exciting title)
	glutDisplayFunc(myDisplay);     // register the redraw function
	myInit();
	glutMainLoop();      // go into a perpetual loop
}


