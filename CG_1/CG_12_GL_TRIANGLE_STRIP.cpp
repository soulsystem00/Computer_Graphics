#include <GL/glut.h>

// 이번에는 GL_TRIANGL_STRIP을 사용하여 그림을 그려보았다.
// GL_TRIANGLE_STRIP은 삼각분할에서 사용되기도 한다.
// 복잡한 그림을 그릴 때 삼각형으로 나누어 그리면 
// 좀 더 빠르게 그릴 수 있다고 한다.
// 아래는 GL_TRIANGLE_STRIP을 사용하면서 
// 각 Vertex별로 색을 다르게 했을 때 나오는 결과를 확인해본 예시이다.

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
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(0.0, 0.0);
	glColor3f(0.2, 0.2, 0.0);
	glVertex2f(0.1, 0.2);
	glColor3f(0.4, 0.4, 0.0);
	glVertex2f(0.2, 0.0);
	glColor3f(0.6, 0.6, 0.0);
	glVertex2f(0.3, 0.2);
	glColor3f(0.8, 0.8, 0.0);
	glVertex2f(0.4, 0.0);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2f(0.5, 0.2);
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