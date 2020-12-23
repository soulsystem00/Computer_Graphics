#include <GL/glut.h>

// GL_TRIANGLE_FAN은 말그대로 FAN(선풍기)를 그린다고 설정하는 것이다. 
// 최초로 주어진 Vertex를 중점으로 2개의 점을 입력받아
// 삼각형을 그려나가게 된다. 
// 점이 1,2,3,4,5 순서대로 왔다고 한다면
// 1,2,3 / 1,2,3 / 1,3,4 / 1,4,5 의 점을 이용하여
// 삼각형을 그리게 된다.

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);      // set the bg color to a bright white
	glMatrixMode(GL_PROJECTION);// set up appropriate matrices- to be explained 
	glLoadIdentity();// to be explained
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);// to be explained
}
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);     // clear the screen 
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(0.0, 0.0);
	glVertex2f(0.5, 0.0);
	glVertex2f(0.3, 0.2);
	glVertex2f(0.0, 0.5);
	glVertex2f(-0.2, 0.3);
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
