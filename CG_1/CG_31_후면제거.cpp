#include <GL/glut.h>

// 후면제거는 물체 뒤에 있는 그림을 그리지 않는 것을 의미한다.
// 후면제거를 해주지 않는다면 물체의 뒤에 있는 그림까지 그려버리게 될 것이다.
// 이러한 방식은 현실의 방식과 맞지 않을 뿐더러
// 많은 자원의 낭비를 초래할 것이다.

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