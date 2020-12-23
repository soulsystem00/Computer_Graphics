#include <GL/glut.h>

// ViewPort는 하나의 화면을 분할해서 사용하는 것을 말한다.
// glViewPort 함수를 통해 사용할 수 있다.
// glViewPort(x시작점, y시작점, 너비, 높이)로 설정 된다.
// 기존의 그려지는 화면이 Viewport의 크기만큼 줄어들게 된다.
// 종횡비 역시 영향을 받게 된다.
// viewport 함수에 주석을 껐다 켜보면 차이를 알 수 있다.

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);      // set the bg color to a bright white
	glMatrixMode(GL_PROJECTION);// set up appropriate matrices- to be explained 
	glLoadIdentity();// to be explained
	gluOrtho2D(0.0, 2.0, 0.0, 2.0);// to be explained
}
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);     // clear the screen 
	glViewport(0,0,200,400);
	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex2f(0.2, 0.2);
	glVertex2f(1.8, 0.2);
	glVertex2f(1.0, 1.8);
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