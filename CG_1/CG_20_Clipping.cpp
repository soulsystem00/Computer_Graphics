#include <GL/glut.h>

// Clipping은 가시공간 밖의 그림이 잘리는 것을 말한다.
// 이번 예시는 그림을 그릴때 가시공간 밖에 그리는 그림이 
// 어떻게 보이는지에 대해 알 수 있는 예시이다.
// 어떻게 보면 당연한 걸 수도 있지만.
// 가시공간, Viewing face 밖의 그림은 잘리는 것을 확인 할 수 있다.

void Display() 
{  
	glClear(GL_COLOR_BUFFER_BIT);  
	glColor3f(0.0, 1.0, 0.0);  
	glBegin(GL_QUADS);  
	glVertex3f(-20, -20, 0);  
	glVertex3f(80, 20, 0);  
	glVertex3f(120, 120, 0); 
	glVertex3f(20, 80, 0); 
	glEnd(); 
	glFlush();  
}  
int main() 
{
	glutInitWindowSize(200, 200); 
	glutInitWindowPosition(100, 100); 
	glutCreateWindow("OpenGL Hello World!");
	glClearColor(1.0, 0.0, 0.0, 0.0);
	glOrtho(0, 200, 0, 200, -1, 1);//orthogonal projection  
	glutDisplayFunc(Display); 
	glutMainLoop(); 
	return 0; 
}
