#include <GL/glut.h>
void myInit(void)   
{
	glClearColor(1.0, 1.0, 1.0, 0.0); // the background color is white   
	glColor3f(1.0f, 0.0f, 0.0f); // the drawing color is black   
	glMatrixMode(GL_PROJECTION);   
	glLoadIdentity();   
	glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);   
}   
void Display()   
{   
	glClear(GL_COLOR_BUFFER_BIT);   
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// 변환은 아래서 부터 적용 됨 
	glTranslatef(0, 0,-15);
	glTranslatef(10, 0, 0); // x축으로 10 만큼 이동
	glRotatef(45, 0, 0, 1); // z축으로 회전
	
	glutWireTeapot(3.0);   
	glFlush();  
}   
int main()
{
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("OpenGL Hello World!");
	glutDisplayFunc(Display);
	myInit();
	glutMainLoop();
	return 0;
}