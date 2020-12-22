#include <cstdlib>
#include <cmath>
#include <iostream>
#include <GL/glut.h>
using namespace std;
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
    glScalef(1.4, 1.4, 1.0); // 스케일링 함수
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