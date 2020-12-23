#include <cmath>
#include <iostream>
#include <GL/glut.h>

using namespace std;

// 이번 예시는 Bump 매핑을 적용시킨 예시이다.
// Bump 매핑은 텍스쳐를 매핑을 시킬 때 
// 굴곡이지게 매핑을 시켜주는 방식이다.
// 이러한 방식은 기존의 도형을 복잡하게 만들 필요 없이
// 텍스쳐 매핑을 바꾸는 방법 만으로도 복잡해보이는 도형을 만들 수 있다는 것이다.

// Globals.
static int isBumpMapped = 0; // Is bump mapping on?

 // Initialization routine.
void setup(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glEnable(GL_DEPTH_TEST); // Enable depth testing.

     // Turn on OpenGL lighting.
    glEnable(GL_LIGHTING);

    // Automatically resize all normals to unit length.
    glEnable(GL_NORMALIZE);

    // Light property vectors.
    float lightAmb[] = { 0.0, 0.0, 0.0, 1.0 };
    float lightDifAndSpec[] = { 1.0, 1.0, 1.0, 0.0 };
    float lightPos[] = { 0.0, 1.0, 0.0, 0.0 };
    float globAmb[] = { 0.2, 0.2, 0.2, 1.0 };

    // Light properties.
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDifAndSpec);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightDifAndSpec);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

    glEnable(GL_LIGHT0); // Enable particular light source.
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globAmb); // Global ambient light.

     // Material property vectors.
    float matAmbAndDif[] = { 0.0, 0.5, 0.5, 1.0 };
    float matSpec[] = { 1.0, 1.0, 1.0, 1.0 };
    float matShine[] = { 50.0 };

    // Material properties.
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, matAmbAndDif);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, matSpec);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, matShine);
}

// Drawing routine.
void drawScene(void)
{
    int i = 0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    gluLookAt(0.0, 5.0, 30.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    // Draw a plane triangular grid. 
    for (float v = 100.0; v > -100.0; v -= 1.0)
    {
        glBegin(GL_TRIANGLE_STRIP);
        for (float u = -100.0; u < 100.0; u += 1.0)
        {
            if (isBumpMapped) glNormal3f(2.0 * cos(2.0 * u), 1.0, 0.0); // Bump-mapped normals.
            else glNormal3f(0.0, 1.0, 0.0); // Original vertical normals.
            glVertex3f(u, 0.0, v - 1.0);
            glVertex3f(u, 0.0, v);
            i++;
        }
        glEnd();
        i++;
    }

    glutSwapBuffers();
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);
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
    case ' ':
        if (isBumpMapped) isBumpMapped = 0;
        else isBumpMapped = 1;
        glutPostRedisplay();
        break;
    default:
        break;
    }
}

// Routine to output interaction instructions to the C++ window.
void printInteraction(void)
{
    cout << "Interaction:" << endl;
    cout << "Press space to toggle between bump mapping on and off." << endl;
}

// Main routine.
int main(int argc, char** argv)
{
    printInteraction();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("bumpMapping.cpp");
    glutDisplayFunc(drawScene);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyInput);
    setup();

    glutMainLoop();
}