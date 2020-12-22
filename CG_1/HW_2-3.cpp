#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <fstream>
#define PI 3.141592
void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0); // the background color is white   
	glColor3f(0.0f, 0.0f, 0.0f); // the drawing color is black   
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-100.0, 100, -100, 100, 10, 20);
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
	glMatrixMode(GL_MODELVIEW);
	
	glEnd();
}

void Hexagon(void)
{
	glBegin(GL_LINE_LOOP);
	glColor3f(0.0f, 0.0f, 0.0f); // Black
	glVertex2f(20, 10);
	glVertex2f(40, 10);
	glVertex2f(55, 30);
	glVertex2f(40, 48);
	glVertex2f(20, 48);
	glVertex2f(5, 30);
}
void Display(void)	// 스택을 사용하여 변환을 분리시킨 예	
{
	glClear(GL_COLOR_BUFFER_BIT);
	glTranslatef(-100.0, 50.0, -15.0);
	//glBegin(GL_POLYGON);
	//int r = 100;
	//for (int i = 0; i < 6; ++i) 
	//{
	//	glVertex2d(r * sin(i / 6 * 2 * PI), r * cos(i / 6 * 2 * PI));
	//}
	for (int i = 0; i < 3; i++)
	{
		glPushMatrix();
		glTranslatef(0, -38, 0);
		Hexagon();
		glPopMatrix();
		glEnd();
	}
	
	glTranslatef(35, -57, 0);
	for (int i = 0; i < 4; i++)
	{
		glPushMatrix();
		glTranslatef(0, 38, 0);
		Hexagon();
		glPopMatrix();
		glEnd();
	}
	glTranslatef(35, 57, 0);
	for (int i = 0; i < 5; i++)
	{
		glPushMatrix();
		glTranslatef(0, -38, 0);
		Hexagon();
		glPopMatrix();
		glEnd();
	}
	glTranslatef(35, -19, 0);
	for (int i = 0; i < 4; i++)
	{
		glPushMatrix();
		glTranslatef(0, 38, 0);
		Hexagon();
		glPopMatrix();
		glEnd();
	}
	glTranslatef(35, 19, 0);
	for (int i = 0; i < 3; i++)
	{
		glPushMatrix();
		glTranslatef(0, -38, 0);
		Hexagon();
		glPopMatrix();
		glEnd();
	}
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