#include <iostream>
#include <GL/glut.h>

using namespace std;

// Blending은 색을 섞는 것을 말한다.
// 그런데 Alpha 값이 1이면 불투명하기 때문에 색이 섞이지 않는다.
// 그렇기 때문에 색을 섞기 위해선 Alpha 값을 조정해주어야 한다.
// 이렇게 조정한 Alpha 값을 바탕으로 
// 색이 섞이게 된다.

// Globals.
static int isWire = 0; // Is wireframe?

// Drawing routine.
void drawScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    if (isWire) glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); else glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Draw square annulus.
    glBegin(GL_TRIANGLE_STRIP);
    glColor4f(1.0, 0.0, 0.0, 0.5);
    glVertex3f(10.0, 10.0, 0.0);
    glVertex3f(70.0, 10.0, 0.0);
    glVertex3f(30.0, 70.0, 0.0);
    glEnd();
    glFlush();
}

// Initialization routine.
void setup(void)
{
    glClearColor(0.0, 0.0, 1.0, 0.0);
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
    switch (key)
    {
    case ' ':
        if (isWire == 0) isWire = 1;
        else isWire = 0;
        glutPostRedisplay();
        break;
    case 27:
        exit(0);
        break;
    default:
        break;
    }
}

// Routine to output interaction instructions to the C++ window.
void printInteraction(void)
{
    cout << "Interaction:" << endl;
    cout << "Press the space bar to toggle between wireframe and filled." << endl;
}

// Main routine.
int main(int argc, char** argv)
{
    printInteraction();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("squareAnnulus1.cpp");
    glutDisplayFunc(drawScene);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyInput);
    setup();
    glutMainLoop();

}



