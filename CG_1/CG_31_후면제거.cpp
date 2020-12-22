#include <GL/glut.h>
// Drawing routine.   
void drawScene(void)   
{   
    glClear(GL_COLOR_BUFFER_BIT);  
    glColor3f(0.0, 0.0, 0.0);   
    gluLookAt(0.0, 10.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);   
    glEnable(GL_CULL_FACE);   
    glCullFace(GL_BACK);   
    glutWireTorus(3.0, 5.0, 15, 15);   
    glFlush();   
}   
// Main routine.   
int main(int argc, char **argv)   
{   
    glutInit(&argc, argv);   
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);  
    glutInitWindowSize(500, 500);   
    glutInitWindowPosition(100, 100);   
    glutCreateWindow("squareOfWalls.cpp");  
    glutDisplayFunc(drawScene);   
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);
    glClearColor(1.0, 1.0, 1.0, 0.0);  
    glutMainLoop();   
}