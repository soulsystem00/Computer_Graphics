#include <cstdlib>
#include <cmath>
#include <iostream>
#include <GL/glut.h>

// 변환은 Vertex에만 적용할 수 있는 것이 아니라
// 기존에 정의되어있는 각종 도형을 그리는 함수에도 적용시킬 수 있다.
// 해당 예시는 Teapot을 그리는 함수에 변환을 적용시킨 예시이다.


void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);       // the background color is white
    glColor3f(1.0f, 0.0f, 0.0f);         // the drawing color is black 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);
}

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT);
    //glTranslatef(0.0, 0.0, -5.0);
    glutWireTeapot(2.0); // 티팟 함수, 크기 지정
    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("box.cpp");
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glutDisplayFunc(drawScene);
    myInit();

    glutMainLoop();
    return 0;
}