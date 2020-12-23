#pragma warning(disable: 4996)
#include <iostream>
#include <fstream>
#include <GL/glut.h>

using namespace std;

// 곡선을 그리는 방법에는 여러가지가 있다.
// 가장 처음에 배운 것은 삼각함수를 이용하여 그리는 것이었다.

// 두번째 방법은 베지에 커브를 사용하는 방법이다.
// 베지에 커브는 각 점에서 가중치를 둔 연산을 통하여
// 점을 그려나가는 방식이다.
// 이러한 방식은 복잡하지만 기초적인 방식이 될 것이다.

// 장점으로는 복잡한 연산이 없이
// 공식 1개만 있으면 각 좌표를 구할 수 있다는 것이다.

// 단점으로는 각 점의 위치가 바뀌면 곡선의 형태도 바뀐다는 것이다.
// 또한 점의 갯수가 늘어날 수록 함수의 차수가 계속해서 증가하기 때문에
// 구현하기 힘들다는 단점이 있다.

// 해당 예시는 control point를 3개로 둔
// 2차 베지에 커브를 확인해보는 예시이다.

// Begin globals.
static float u = 0.0; // Curve parameter.
static char theStringBuffer[10]; // String buffer.
static long font = (long)GLUT_BITMAP_8_BY_13; // Font selection.

  // Control points.
static float ctrlpoints[3][3] =
{
{ -40.0, -20.0, 0.0 },{ 0.0, 40.0, 0.0 },{ 40.0, -20.0, 0.0 }
};
// End globals.

// Routine to draw a bitmap character string.
void writeBitmapString(void* font, const char* string)
{
    const char* c;

    for (c = string; *c != '\0'; c++) glutBitmapCharacter(font, *c);
}

// Routine to convert floating point to char string.
void floatToString(char* destStr, int precision, float val)
{
    sprintf(destStr, "%f", val);
    destStr[precision] = '\0';
}

// Initialization routine.
void setup(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
}

// Drawing routine.
void drawScene(void)
{
    int i;

    glClear(GL_COLOR_BUFFER_BIT);

    // Write u value.
    glColor3f(0.0, 0.0, 0.0);
    floatToString(theStringBuffer, 4, u);
    glRasterPos3f(-40.0, 40.0, 0.0);
    writeBitmapString((void*)font, "u = ");
    writeBitmapString((void*)font, theStringBuffer);

    // The Bezier curve is drawn from 0 to parameter value.
    glColor3f(1.0, 0.0, 1.0);
    glLineWidth(2.0);
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 3, &ctrlpoints[0][0]);
    glEnable(GL_MAP1_VERTEX_3);
    glMapGrid1f(100, 0.0, 1.0);
    glEvalMesh1(GL_LINE, 0, (int)(u * 100));
    glLineWidth(1.0);

    // The control points as dots.
    glPointSize(5.0);
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POINTS);
    for (i = 0; i < 3; i++)
        glVertex3fv(&ctrlpoints[i][0]);
    glEnd();

    // The lines joining the control points.
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_STRIP);
    for (i = 0; i < 3; i++)
        glVertex3fv(&ctrlpoints[i][0]);
    glEnd();

    // The point interpolating between the first two control points.
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 2, &ctrlpoints[0][0]);
    glEnable(GL_MAP1_VERTEX_3);
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    glEvalCoord1f(u);
    glEnd();

    // The point interpolating between the last two control points.
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 2, &ctrlpoints[1][0]);
    glEnable(GL_MAP1_VERTEX_3);
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POINTS);
    glEvalCoord1f(u);
    glEnd();

    // The line joining the two points drawn above.
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINES);
    glVertex3f((1 - u) * ctrlpoints[0][0] + u * ctrlpoints[1][0],
        (1 - u) * ctrlpoints[0][1] + u * ctrlpoints[1][1],
        0.0);
    glVertex3f((1 - u) * ctrlpoints[1][0] + u * ctrlpoints[2][0],
        (1 - u) * ctrlpoints[1][1] + u * ctrlpoints[2][1],
        0.0);
    glEnd();

    // The point interpolating between the two points drawn above.
    glColor3f(1.0, 0.0, 0.0);
    glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 3, &ctrlpoints[0][0]);
    glEnable(GL_MAP1_VERTEX_3);
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POINTS);
    glEvalCoord1f(u);
    glEnd();

    glutSwapBuffers();
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        exit(0);
        break;
    default:
        break;
    }
}

// Callback routine for non-ASCII key entry.
void specialKeyInput(int key, int x, int y)
{
    if (key == GLUT_KEY_LEFT)
        if (u > 0.02) u -= 0.02;
    if (key == GLUT_KEY_RIGHT)
        if (u < 0.98) u += 0.02;
    glutPostRedisplay();
}

// Routine to output interaction instructions to the C++ window.
void printInteraction(void)
{
    cout << "Interaction:" << endl;
    cout << "Press the left/right arrows to decrease/increase the curve parameter u." << endl;
}

// Main routine.
int main(int argc, char** argv)
{
    printInteraction();
    glutInit(&argc, argv);


    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("deCasteljau3.cpp");
    glutDisplayFunc(drawScene);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyInput);
    glutSpecialFunc(specialKeyInput);


    setup();

    glutMainLoop();
}