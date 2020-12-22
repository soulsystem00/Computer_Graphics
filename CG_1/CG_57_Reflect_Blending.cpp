
#include <iostream>

#include<GL/glut.h>

using namespace std;

void setup(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST); // Enable depth testing.

    // Turn on OpenGL lighting.
    glEnable(GL_LIGHTING);

    // Light property vectors.
    float lightAmb[] = { 0.2, 0.2, 0.2, 1.0 };
    float lightDifAndSpec[] = { 1.0, 1.0, 1.0, 1.0 };
    float lightPos[] = { 30.0, 30.0, 30.0, 1.0 };

    // Light properties.
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDifAndSpec);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightDifAndSpec);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glEnable(GL_LIGHT0); // Enable particular light source.

 // Material property vectors.
    float matSpec[] = { 1.0, 1.0, 1.0, 1.0 };
    float matDiffuse[] = { 0.0, 1.0, 0.0, 1.0 };
    float matShine[] = { 50.0 };

    // Material properties.
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, matSpec);
    glMaterialfv(GL_FRONT, GL_SHININESS, matShine);


}

// Drawing routine.
void drawScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(5.0, 10.0, 30.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);


    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    glutSolidTorus(2.0, 5.0, 80, 80);
    glTranslatef(15.0, 0.0, 0.0);
    glutSolidCube(6.0);
    glPopMatrix();

    glPushMatrix();
    glScalef(1.0, -1.0, 1.0);
    glTranslatef(0, 10, 0);
    glRotatef(90, 1, 0, 0);
    glutSolidTorus(2.0, 5.0, 80, 80);
    glTranslatef(15.0, 0.0, 0.0);
    glutSolidCube(6.0);
    glPopMatrix();
    glEnable(GL_BLEND); // Enable blending.
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // Specify blending parameters. 

    float matDiffuse1[] = { 1.0, 1.0,1.0, 0.5 };
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiffuse1);
    glTranslatef(0.0, -3.2, 0.0);
    glScalef(2.0, 0.01, 2.0);
    glutSolidCube(20.0);
    glPopMatrix();

    glFlush();
}


// Main routine.
int main(int argc, char** argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("ballAndTorusReflected.cpp");
    setup();
    glutDisplayFunc(drawScene);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);
    glutMainLoop();
}



