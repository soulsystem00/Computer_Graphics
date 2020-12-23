#include <GL/glut.h>

// Sissor box는 가시공간, 뷰포트를 넘어
// 최종적으로 보여질 공간을 의미한다.
// 즉 물체가 가시공간, 뷰포트 안에 있다 하더라도
// Sissor Box 밖에 있다면 보여지지 않게 된다.
// 또한 Sissor Box는 가시공간, 뷰포트와 다르게
// 전체화면으로 보여지지 않는다.
// 즉, 전체화면에서 보여질 부분만 따로 설정할 수 있다는 것이다.
// 이렇게 설정을 한다면 나머지 부분은 보여지지 않게 처리가 되고
// Sissor Box 안에 보여지는 그림만 비춰지게 될 것이다.

GLfloat size = 2.0;
GLfloat x = 0;
GLfloat dx = 0.10;
static float t = 0.0; // Time parameter.
void DoTimer(int value)
{
    x += dx;
    if (x + size > 3 || x - size < -3) {
        dx *= -1;
    }
    glutPostRedisplay();
    glutTimerFunc(30, DoTimer, 1);
}

void drawScene()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_SCISSOR_TEST);
    glScissor(0.0, 0.0, 250.0, 250.0);

    glBegin(GL_POLYGON);
    glVertex2f(x, size);
    glVertex2f(x - size, -size);
    glVertex2f(x + size, -size);
    glEnd();
    glutSwapBuffers();
}


int main()
{
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL");
    glutDisplayFunc(drawScene);
    glutTimerFunc(30, DoTimer, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-5.0, 5.0, -5.0, 5.0, -1.0, 1.0);
    glutMainLoop();
    return 0;
}