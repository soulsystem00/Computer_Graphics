#include <cstdlib>
#include <cmath>
#include <GL/glut.h>

// Alpha 값이란 색상에서의 투명도를 의미한다.
// Alpha 값이 1이면 불투명을 0이면 투명을 의미한다.
// 이러한 Alpha 값을 적용을 시켜도 
// Alpha test를 활성화시키지 않는다면 alpha 값은 적용이 되지 않는다.
// 또한 alpha test 를 거쳐가는 방식에는 여러 방식들이 있다.
// 이러한 것들을 테스트해보는 예시이다.

void display(void)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);

	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_LESS, 0.5);

	glBegin(GL_TRIANGLES);
	glColor4f(1.0, 0.0, 0.0, 0.7);
	glVertex3f(0.1, 0.9, 0.0);
	glVertex3f(0.1, 0.1, 0.0);
	glVertex3f(0.7, 0.5, 0.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor4f(0.0, 1.0, 0.0, 0.3);
	glVertex3f(0.9, 0.9, 0.0);
	glVertex3f(0.3, 0.5, 0.0);
	glVertex3f(0.9, 0.1, 0.0);
	glEnd();


	glFlush();
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(700, 700);
	glutCreateWindow(argv[0]);
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 1, 0, 1, -1, 1);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

