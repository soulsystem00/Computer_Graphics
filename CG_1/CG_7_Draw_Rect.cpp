#include <GL/glut.h>

// 그림을 그릴때 glBegin을 통하여
// Vertex를 하나씩 지정해주면서 그릴 수도 있지만
// 내장되어있는 함수를 사용할 수도 있다.
// 해당 예시는 사각형을 그려주는 glRect함수를 사용한 예시이다.
// glRect(x1, y1, x2, y2)
// 즉, Vertex 2개를 가지고 사각형을 그리는 방식이다.

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
	glRecti(20, 20, 100, 70);
	glColor3f(0.2, 0.2, 0.2);
	glRecti(70, 50, 150, 130);
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
