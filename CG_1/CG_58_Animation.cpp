#include <GL/glut.h>

// 이번에는 타이머 콜백함수를 사용하여
// 그림이 이동하게 만들어보았다.
// 이를 위하여 glutTimerFunc를 사용하였다.
// 추가로 glFlush가 아닌 glutSwapBuffer를 사용해주었고
// glutInitDisplayMode(GLUT_SINGLE); 이 아닌 glutInitDisplayMode(GLUT_DOUBLE);을 사용해주었다.
// 이는 애니메이션을 그릴 때 
// 버퍼가 하나 있으면 버퍼가 지워지는 시간과 그림이 그려지는 시간의 차이로 인하여
// 자연스러운 애니메이션이 연출이 안되기 때문이다.
// 이에 버퍼를 2개로 두어 
// 이러한 차이를 줄이고자 한것이다.

GLfloat size = 0.5;
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
    glutCreateWindow("OpenGL");
    glutDisplayFunc(drawScene);
    glutTimerFunc(30, DoTimer, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-5.0, 5.0, -5.0, 5.0, -1.0, 1.0);
    glutMainLoop();
    return 0;
}