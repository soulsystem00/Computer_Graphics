#include <math.h>
#include <GL/glut.h>           //   we will use GLUT (GL UTILITY TOOLKIT)

double function1_x(double u)
{
    return -17 * pow((1 - u), 3) + -33 * pow((1 - u), 2) * u + 3 * (1 - u) * pow(u, 2) * -1 + pow(u, 3) * -1;
}
double function1_y(double u)
{
    return 8 * pow((1 - u), 3) + 33 * pow((1 - u), 2) * u + 3 * (1 - u) * pow(u, 2) * 4 + pow(u, 3) * -4;
}

double function2_x(double u)
{
    return -1 * (1 - u) * (1 - u) * (1 - u) + -9 * (1 - u) * (1 - u) * u + 3 * (1 - u) * u * u * -20 + u * u * u * -28;
}
double function2_y(double u)
{
    return -4 * (1 - u) * (1 - u) * (1 - u) + 3 * (1 - u) * (1 - u) * u * -14 + 3 * (1 - u) * u * u * -18 + u * u * u * -5;
}
void Display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 0.0);
    int i;
    int NUM = 1000;
    double u;
    double v;

    glBegin(GL_LINE_STRIP);
    glVertex3f(-17.0, 8.0, 0.0);
    glVertex3f(-14.0, 23.0, 0.0);
    glVertex3f(0.0, 23.0, 0.0);
    glEnd();

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_STRIP);
    glVertex3f(-17.000000, 8.000000, 0.000000);
    glVertex3f(-11.000000, 11.000000, 0.000000);
    glVertex3f(-1.000000, 4.000000, 0.000000);
    glVertex3f(-1.000000, -4.000000, 0.000000);
    glVertex3f(-1.000000, -4.000000, 0.000000);
    glVertex3f(-3.000000, -14.000000, 0.000000);
    glVertex3f(-20.000000, -18.000000, 0.000000);
    glVertex3f(-28.000000, -5.000000, 0.000000);
    glEnd();

    glPointSize(5);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    glVertex3f(-17.000000 ,8.000000, 0.000000);
    glVertex3f(-11.000000 ,11.000000,0.000000);
    glVertex3f(-1.000000, 4.000000 ,0.000000);
    glVertex3f(-1.000000 ,- 4.000000, 0.000000);
    glVertex3f(-1.000000 ,- 4.000000, 0.000000);
    glVertex3f(-3.000000, - 14.000000, 0.000000);
    glVertex3f(-20.000000, - 18.000000, 0.000000);
    glVertex3f(-28.000000 ,- 5.000000, 0.000000);
    glEnd();



    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_LINE_STRIP);
    for (i = 0; i < NUM; i++) // 첫번째 곡선 U값 증가
    {
        u = double(i) / (NUM * 1.0);
        v = u + 1 / (NUM * 1.0);
        glVertex2f(function1_x(u),function1_y(u));
        glVertex2f(function1_x(v), function1_y(v));
    }
    glEnd();

    glBegin(GL_LINE_STRIP);
    for (i = 0; i < NUM; i++) // 두번째 곡선 U값 증가
    {
        u = double(i) / (NUM * 1.0);
        v = u + 1 / (NUM * 1.0);
        glVertex2f(function2_x(u), function2_y(u));
        glVertex2f(function2_x(v), function2_y(v));
    }
    glEnd();
    glFlush();
}
int main() {
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(300, 300);
    glutCreateWindow("OpenGL Hello World!");
    glutDisplayFunc(Display);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    //gluOrtho2D(0, 5, -1, 2);
    glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
    glutMainLoop();
    return 0;
}