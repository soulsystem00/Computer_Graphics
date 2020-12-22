#include <iostream>
#include <GL/glut.h>
using namespace std;

// Begin globals.
static int numVal = 0, order = 4, askOrder = 0;
static long font = (long)GLUT_BITMAP_8_BY_13; // Font selection.

  // Control points.
static float controlPoints[6][3] =
{
{ -17.0, 8.0, 0.0 },{ -11.0, 11.0, 0.0 },{ -1.0, 5.0, 0.0 },
{ -1.0, -4.0, 0.0 },{ 0, 0.0, 0.0 },{ 0, 0.0, 0.0 }
};

// Control point values stored unchanged for use on reset.
static float originalControlPoints[6][3] =
{
{ -1.0, -4.0, 0.0 },{ -3.0, -14.0, 0.0 },{ -20.0, -17.0, 0.0 },
{ -25.0, -5.0, 0.0 },{0.0, 0.0, 0.0 },{ 0, 0.0, 0.0 }
};
// End globals.

// Initialization routine.
void setup(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
}

// Routine to restore control points to original values.
void restoreControlPoints(void)
{
    int i, j;
    for (i = 0; i < 6; i++)
        for (j = 0; j < 3; j++)
            controlPoints[i][j] = originalControlPoints[i][j];
}

// Routine to draw a bitmap character string.
void writeBitmapString(void* font, const char* string)
{
    const char* c;

    for (c = string; *c != '\0'; c++) glutBitmapCharacter(font, *c);
}

// Drawing routine.
void drawScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);

    if (askOrder == 1)
        // First screen.
    {
        glColor3f(0.0, 0.0, 0.0);
        glRasterPos3f(-25.0, 0.0, 0.0);
        writeBitmapString((void*)font, "Show Bezier curve of order: ");

        glColor3f(1.0, 0.0, 0.0);
        glRasterPos3f(20.0, 0.0, 0.0);
        switch (order)
        {
        case 2:
            writeBitmapString((void*)font, "2");
            break;
        case 3:
            writeBitmapString((void*)font, "3");
            break;
        case 4:
            writeBitmapString((void*)font, "4");
            break;
        case 5:
            writeBitmapString((void*)font, "5");
            break;
        case 6:
            writeBitmapString((void*)font, "6");
            break;
        default:
            break;
        }
    }
    else
        // Second screen.
    {
        int i;

        // Draw the control polygon in light gray.
        glColor3f(0, 0, 0);
        //glLineWidth(3);
        glBegin(GL_LINE_STRIP);
        glVertex3f(-17.0, 8.0, 0.0);
        glVertex3f(-14.0, 23.0, 0.0);
        glVertex3f(0.0, 23.0, 0.0);
        glEnd();

        glColor3f(0.7, 0.7, 0.7);
        glBegin(GL_LINE_STRIP);
        for (i = 0; i < order; i++)
            glVertex3fv(controlPoints[i]);
        glEnd();

        glBegin(GL_LINE_STRIP);
        for (i = 0; i < order; i++)
            glVertex3fv(originalControlPoints[i]);
        glEnd();

        // Specify and enable the Bezier curve.
        glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, order, controlPoints[0]);
        glEnable(GL_MAP1_VERTEX_3);

        // Draw the Bezier curve by defining a sample grid and evaluating on it.
        glColor3f(0.0, 0.0, 0.0);
        glMapGrid1f(100, 0.0, 1.0);
        glEvalMesh1(GL_LINE, 0, 100);

        // Specify and enable the Bezier curve.
        glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, order, originalControlPoints[0]);
        glEnable(GL_MAP1_VERTEX_3);

        // Draw the Bezier curve by defining a sample grid and evaluating on it.
        glColor3f(0.0, 0.0, 0.0);
        glMapGrid1f(100, 0.0, 1.0);
        glEvalMesh1(GL_LINE, 0, 100);
        // Draw the control points as dots.
        glPointSize(5.0);
        glColor3f(0.0, 1.0, 0.0);
        glBegin(GL_POINTS);
        for (i = 0; i < order; i++)
        {
            glVertex3fv(controlPoints[i]);
            printf("%f %f %f\n", controlPoints[i][0], controlPoints[i][1], controlPoints[i][2]);
        }


        glEnd();

        glBegin(GL_POINTS);
        for (i = 0; i < order; i++)
        {
            glVertex3fv(originalControlPoints[i]);
            printf("%f %f %f\n", originalControlPoints[i][0], originalControlPoints[i][1], originalControlPoints[i][2]);
        }
        // Highlight selected control point,
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_POINTS);
        glVertex3fv(controlPoints[numVal]);
        glEnd();
    }
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
    case 13:
        askOrder = 0;
        glutPostRedisplay();
        break;
    case 127:
        askOrder = 1;
        order = 2;
        restoreControlPoints();
        glutPostRedisplay();
        break;
    case ' ':
        if (askOrder == 0)
        {
            if (numVal < order - 1) numVal++;
            else numVal = 0;
        }
        glutPostRedisplay();
        break;
    default:
        break;
    }
}

// Callback routine for non-ASCII key entry.
void specialKeyInput(int key, int x, int y)
{
    if (key == GLUT_KEY_UP)
    {
        if (askOrder == 1)
        {
            if (order < 6) order += 1;
        }
        else
            controlPoints[numVal][1] += 1.0;
    }
    if (key == GLUT_KEY_DOWN)
    {
        if (askOrder == 1)
        {
            if (order > 2) order -= 1;
        }
        else
            controlPoints[numVal][1] -= 1.0;
    }
    if (key == GLUT_KEY_LEFT) controlPoints[numVal][0] -= 1.0;
    if (key == GLUT_KEY_RIGHT) controlPoints[numVal][0] += 1.0;

    //printf("%d %d\n", controlPoints[0][0], controlPoints[0][1]);
    //printf("%d %d\n", controlPoints[1][0], controlPoints[1][1]);
    //printf("%d %d\n", controlPoints[2][0], controlPoints[2][1]);
    //printf("%d %d\n", controlPoints[3][0], controlPoints[3][1]);
    glutPostRedisplay();
}

// Routine to output interaction instructions to the C++ window.
void printInteraction(void)
{
    cout << "Interaction:" << endl;
    cout << "Press the up/down arrows to select an order and press enter." << endl
        << "Press space to select a control point." << endl
        << "Press the arrow keys to move the selected control point." << endl
        << "Press delete to reset." << endl;
}

// Main routine.
int main(int argc, char** argv)
{
    printInteraction();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("bezierCurves.cpp");
    glutDisplayFunc(drawScene);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyInput);
    glutSpecialFunc(specialKeyInput);



    setup();

    glutMainLoop();
}