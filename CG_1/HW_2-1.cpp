#include <GL/glut.h>
void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0); // the background color is white   
	glColor3f(0.0f, 0.0f, 0.0f); // the drawing color is black   
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-20.0, 20.0, -20.0, 20.0, 10, 20);
}

//void Display(void)	// 이전 변환이 모든 물체에 적용 된 예
//{   
//	glClear(GL_COLOR_BUFFER_BIT);   
//	glColor3f(0.0, 0.0, 0.0);   
//	glMatrixMode(GL_MODELVIEW);   
//	glLoadIdentity();   
//	glTranslatef(0.0, 0.0, -15.0);   
//	glScalef(1.0, 2.0, 1.0);   
//	glutWireCube(5.0);   
//	glTranslatef(0.0, 7.0, 0.0);   
//	glutWireSphere(2.0, 10, 8);   
//	glFlush();   
//}   

void Spoke(void)
{
	glBegin(GL_LINE_STRIP);
	glVertex3f(1.6, 1, 0);
	glVertex3f(4, 1, 0);
	glVertex3f(7, 4, 0);
	glVertex3f(8, 4, 0);
	glVertex3f(5, 1, 0);
	glVertex3f(8, 1, 0);
	glVertex3f(9.5f, 3, 0);
	glVertex3f(10.5f, 3, 0);
	glVertex3f(9, 1, 0);
	glVertex3f(14, 1, 0);
	glVertex3f(15, 0, 0);
	glEnd();
}

void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glTranslatef(0.0, 0.0, -15.0);
	for (int i = 0; i < 360; i += 60)
	{
		glRotated(i, 0, 0, 1);
		Spoke();
		glScalef(1, -1, 1);
		Spoke();
	}
	glEnd();
	glFlush();
}

int main()
{
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("OpenGL Hello World!");
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glutDisplayFunc(Display);
	myInit();
	glutMainLoop();
	return 0;
}