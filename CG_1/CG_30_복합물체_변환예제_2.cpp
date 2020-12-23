#include <GL/glut.h>

// 이전 예시를 통해 하나의 변환을 따로 처리하지 않으면
// 모든 물체에 영향을 미친다는 것을 알아보았다.
// 이제 이전 변환이 다른 물체에 영향을 미치지 않도록 하는 예시를 알아보고자 한다.

// 이전 변환이 다른 물체에 영향을 미치지 않게 하기 위해선
// 스택을 사용하면 된다.
// 스택에 변환을 넣고
// Pop을 시켜 물체에 영향을 주게한다면
// 해당 변환은 pop을 시켰을 때만 영향을 미치고
// 없어질 것이다.

// 이렇게 스택을 사용하기 위해
// glPushMatrix() glPopMatrix()를 사용하였다.
// 원하는 범위만큼의 변환을 이 안에 넣어주면
// 그곳에서만 영향을 미치고 없어지게 된다.


void myInit(void)   
{
	glClearColor(1.0, 1.0, 1.0, 0.0); // the background color is white   
	glColor3f(1.0f, 0.0f, 0.0f); // the drawing color is black   
	glMatrixMode(GL_PROJECTION);   
	glLoadIdentity();   
	glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);   
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

void Display(void)	// 스택을 사용하여 변환을 분리시킨 예	
{   
	glClear(GL_COLOR_BUFFER_BIT);   
	glColor3f(0.0, 0.0, 0.0);   
	glMatrixMode(GL_MODELVIEW);   
	glLoadIdentity();   
	glTranslatef(0.0, 0.0, -15.0);   
	glPushMatrix();   
	glScalef(1.0, 2.0, 1.0);   
	glutWireCube(5.0);   
	glPopMatrix();   
	glTranslatef(0.0, 7.0, 0.0);   
	glutWireSphere(2.0, 10, 8);   
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