#include <GL/glut.h>

// GL_TRIANGLE_FAN�� ���״�� FAN(��ǳ��)�� �׸��ٰ� �����ϴ� ���̴�. 
// ���ʷ� �־��� Vertex�� �������� 2���� ���� �Է¹޾�
// �ﰢ���� �׷������� �ȴ�. 
// ���� 1,2,3,4,5 ������� �Դٰ� �Ѵٸ�
// 1,2,3 / 1,2,3 / 1,3,4 / 1,4,5 �� ���� �̿��Ͽ�
// �ﰢ���� �׸��� �ȴ�.

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
