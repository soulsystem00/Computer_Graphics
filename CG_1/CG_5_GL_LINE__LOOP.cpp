#include <GL/glut.h>

// GL_LINE�� Vertex�� 2���� ��� ���� �׸��� �ȴ�.  
// �׷��� ������ ��� Vertex�� ������ �Ǵ� ���´� �׷����� �ʰ� �Ǵµ�
// �̷��� �׸��� �׸��� ���ؼ� GL_LINE_LOOP�� ����ϸ� �ȴ�.
// �ش� �����̴�.  
// ��� ���� ����Ǿ� �ִ� ���� �� �� �ִ�.
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