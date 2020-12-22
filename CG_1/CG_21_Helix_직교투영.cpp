#include <GL/glut.h>
#include <math.h>

#define PI 3.141592

void myInit()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50.0, 50.0, -50.0, 50.0, 0.0, 100.0); // ��������

    //glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0); // �������� Perspective projection
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