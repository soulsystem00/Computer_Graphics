#include <cstdlib>
#include <cmath>
#include <iostream>
#include <GL/glut.h>
using namespace std;

// 이번 예시는 변환에서의 스케일링에 관한 예시이다.
// 스케일링 함수를 사용하면 
// 기존의 Vertex에서 값이 증가하여
// 도형의 크기가 커지는 것을 알 수 있다.
// 각 Vertex를 glscale함수의 인자만큼 
// 곱한 것이 scaling의 결과가 된다.
// 이번 예시에서 translate를 하지 않았음에도 불구하고
// 원의 위치가 옮겨진것을 볼 수 있는데
// 이것은 원의 중점이 0이 아니기 때문에
// 곱셈의 영향을 받기 때문이다.


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
    //glScalef(1.4, 1.4, 1.0); // 스케일링 함수
    drawDisc(20.0, 50, 50, 0.0);
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