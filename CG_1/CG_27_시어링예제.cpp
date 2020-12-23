#include <cstdlib>
#include <cmath>
#include <iostream>
#include <GL/glut.h>

// 시어링이란 물체를 한쪽으로 밀어내는 것을 의미한다.
// 정사각형의 한 꼭짓점을 잡고 밀면 
// 사각형은 평행사변형으로 변할 것이다.
// 이러한 것을 시어링(전단)이라고 한다.
// OpenGL에는 관현 함수가 없기 때문에
// 직접 행렬에 전단 행렬을 곱해주는 식으로 구현해주었다.

float matrixdata[16] = // Shear matrix. 시어링을 위한 행렬
{
   1.0, 0, 0.0, 0.0, 0.2, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0
};


void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);       // the background color is white
    glColor3f(1.0f, 0.0f, 0.0f);         // the drawing color is black 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-5, 5, -5, 5, -1, 1);

}

void drawScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    //glMultMatrixf(matrixdata);// 시어링 행렬을 직접 곱해줘서 시어링을 구현
    glBegin(GL_QUADS);
    glVertex3f(-1, 1, 0.0);
    glVertex3f(-1, -1, 0.0);
    glVertex3f(1, -1, 0.0);
    glVertex3f(1, 1, 0.0);
    glEnd();
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