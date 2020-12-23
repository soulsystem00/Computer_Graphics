#include <GL/glut.h>

// 지금까지 알아본 변환은 각 물체에 대해 1개씩만 적용가능한 것이 아니다.
// 한 물체에 대해 이동, 회전, 스케일링, 전단을 모두 적용시킬 수도 있다.
// 이렇게 여러개의 변환을 적용시켰을 때의 예제이다.
// 이러한 변환은 코드로 보았을 때 
// 아래에 있는 코드부터 적용이 된다.
// 이에 코드를 짤때 헷갈리지 않도록 해야한다.

// 변환은 행렬의 곱을 바탕으로 이루어진다.
// 행렬의 곱은 교환법칙이 성립하지 않기 때문에
// 같은 변환을 적용하더라도 
// 그 순서에 따라 결과물이 달라질 수 있다.

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