#include <GL/glut.h>

// GL_LINE은 Vertex를 2개씩 묶어서 선을 그리게 된다.  
// 그렇기 때문에 모든 Vertex가 연결이 되는 형태는 그려지지 않게 되는데
// 이러한 그림을 그리기 위해선 GL_LINE_LOOP를 사용하면 된다.
// 해당 예시이다.  
// 모든 점이 연결되어 있는 것을 볼 수 있다.
void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);      // set the bg color to a bright white
	glColor3f(0.0f, 0.0f, 0.0f);           // set the drawing color to black 
	glMatrixMode(GL_PROJECTION);// set up appropriate matrices- to be explained 
	glLoadIdentity();// to be explained
	gluOrtho2D(0.0, 100.0, 0.0, 100.0);// to be explained
}
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);     // clear the screen 
	glLineWidth(4.0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(20, 10);         // draw some points (don't know how many)
	glVertex2i(50, 10);
	glVertex2i(20, 80);
	glVertex2i(50, 80);
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