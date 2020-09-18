#include <GL/glut.h>
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
    glBegin(GL_POLYGON);
    glVertex2f(0.8, 0.2);
    glVertex2f(0.4, 0.4);
    glVertex2f(0.2, 0.8);
    glVertex2f(0.2, 0.2);
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
