#include <GL/glut.h>

// 직교투영의 예시이다.
// 가시공간을 3D로 놓았고,
// 각 Vertex의 z좌표를 0으로 놓았다.
// 이때 가시공간의 Viewing face가 -1이지만
// z좌표가 0인 그림도 정상적으로 보여지는 것을 확인 할 수 있었다.


void Display() 
{   
      glClear(GL_COLOR_BUFFER_BIT);   
      glColor3f(0.0, 1.0, 0.0);   
      glBegin(GL_QUADS);   
      glVertex3f(10, 10, 0.0);   
      glVertex3f(20, 10, 0.0);   
      glVertex3f(20, 20, 0);   
      glVertex3f(10, 20, 0);   
      glEnd();   
      glFlush();   
}   
int main()
{
    glutInitWindowSize(200, 200);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL Hello World!");
    glClearColor(1.0, 0.0, 0.0, 0.0);
    glOrtho(0, 100, 0, 100, -1, 1); //orthogonal projection   
    glutDisplayFunc(Display);
    glutMainLoop();
    return 0;
}