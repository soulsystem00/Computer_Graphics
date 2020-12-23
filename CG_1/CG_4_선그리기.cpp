#include <GL/glut.h>

// glBegin을 사용하여 어떤 도형을 그릴 건지 설정할 수 있음
// GL_LINES는 선을 그린다는 명령이 됨  
// 이때 앞의 2개의 Vertex를 사용하여 하나의 선을 그림
// 여러개의 Vertex가 주어지면 2개씩 묶어 선을 그림  
// 모든 Vertex가 이어지진 않기 때문에 
// 해당 동작을 원하면 GL_LINE_LOOP와 같은 설정이 필요함
void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);      // set the bg color to a bright white
	glColor3f(0.0f, 0.0f, 0.0f);           // set the drawing color to black 
	glMatrixMode(GL_PROJECTION);// set up appropriate matrices- to be explained 
	glLoadIdentity();// to be explained
	gluOrtho2D(0.0, 50.0, 0.0, 50.0);// to be explained
}
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);     // clear the screen 
	glLineWidth(4.0);
	glBegin(GL_LINES);
	glVertex2i(10, 20);         // draw some points (don't know how many)
	glVertex2i(40, 20);
	glVertex2i(20, 10);
	glVertex2i(20, 40);
	glEnd();
	glFlush();		                  // send all output to display 
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