#include <cstdlib>
#include <cmath>
#include <iostream>
#include <GL/glut.h>

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
    glTranslatef(0.0, 0.0, -15.0);
    glScalef(2.0, 2.0, 2.0);
    glutWireTeapot(5.0);
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