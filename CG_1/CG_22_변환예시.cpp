#include <cstdlib>
#include <cmath>
#include <iostream>
#include <GL/glut.h>
using namespace std;

// 도형을 그리고나서 도형의 크기나 위치 같은 것들을 바꿀수가 있다.
// 이것을 변환이라고 부른다.
// glTranslate로 위치를 바꿀 수 있고
// glscale로 크기를 바꿀 수 있다.
// 해당 예시는 glTranslate를 사용하여 도형의 위치를 옮긴 예시이다.


#define PI 3.14159265
#define N 40.0 

void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);       // the background color is white
    glColor3f(1.0f, 0.0f, 0.0f);         // the drawing color is black 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 100.0, 0.0, 100.0, -1, 1.0);
}


void drawDisc(float R, float X, float Y, float Z)
{
    float t;
    int i;
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(X, Y, Z);
    for (i = 0; i <= N; ++i)
    {
        t = 2 * PI * i / N;
        glVertex3f(X + cos(t) * R, Y + sin(t) * R, Z);
    }
    glEnd();
}
void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glTranslatef(20,20,0); // transrate func
    drawDisc(20.0, 50.0, 50.0, 0.0);
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