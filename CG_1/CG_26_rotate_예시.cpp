#include <cstdlib>
#include <cmath>
#include <iostream>
#include <GL/glut.h>

// �̹� ���ô� ��ȯ���� rotate
// ��, ȸ���� �����Ų �����̴�.
// glRotatef(x�� ȸ������, y�� ȸ������, z�� ȸ������)

void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);       // the background color is white
    glColor3f(1.0f, 0.0f, 0.0f);         // the drawing color is black 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);

}

void drawScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glTranslatef(0.0, 0.0, -15.0);   // 
    glRotatef(45, 0, 0, 1);
    glutWireTeapot(5.0); // Box.
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