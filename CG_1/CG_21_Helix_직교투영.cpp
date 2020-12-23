#include <GL/glut.h>
#include <math.h>

// 기존의 glOrtho는 그림의 Z의 좌표가
// 그대로 Viewing face의 z좌표로 바뀌면서 보여지게 된다.
// 이러한 방식은 현실의 방식과는 차이가 있다.
// 멀리있는 물체는 작게보이고
// 가까이있는 물체는 크게 보이는 것이 현실의 투영방법이다.
// 이러한 것을 반영하여 투영이 되는 가시공간이 바로 
// glFrustum을 이용한 예시이다.


#define PI 3.141592

void myInit()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glOrtho(-50.0, 50.0, -50.0, 50.0, 0.0, 100.0); // ��������

    glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0); // �������� Perspective projection
}



void Display() {
    glClear(GL_COLOR_BUFFER_BIT);
    float R = 20.0; // Radius of helix.
    float t; // Angle parameter.
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_STRIP);
    for (t = -10 * PI; t <= 10 * PI; t += PI / 20.0)
        glVertex3f(R * cos(t), R * sin(t), t - 60.0);
    glEnd();
    glFlush();
}

int main() {

    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL Hello World!");
    glutDisplayFunc(Display);
    myInit();
    glutMainLoop();
    return 0;
}