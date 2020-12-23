#include <GL/glut.h>

// GL_TRIANGLES를 사용하여 삼각형을 그려보았다.
// 중요한 것은 삼각형을 그리는 Vertex의 순서이다.
// 이 순서를 바탕으로 회전하는 방향이 결정이 되는데
// 반시계 회전이면 전면, 시계 방향이면 후면으로 간주되기 때문이다. 
// 지금은 Vertex를 어떻게 주던지 간에 삼각형이 잘 그려질 것이다.

void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);      // set the bg color to a bright white
    glMatrixMode(GL_PROJECTION);// set up appropriate matrices- to be explained 
    glLoadIdentity();// to be explained
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);// to be explained
}
void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);     // clear the screen 
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.2, 0.2);
    glVertex2f(0.2, 0.8);
    glVertex2f(0.8, 0.2);
    glEnd();
    glFlush();		                 // send all output to display 
}
void main(int argc, char** argv)
{
    glutInitWindowSize(400, 400);     // set the window size
    glutInitWindowPosition(100, 150); // set the window position on the screen
    glutCreateWindow("my first attempt"); // open the screen window(with its exciting title)
    glutDisplayFunc(myDisplay);     // register the redraw function
    myInit();
    glutMainLoop(); 		     // go into a perpetual loop
}
