#include <GL/glut.h>


//gluOrtho2D 를 통해 가시공간을 설정함
//glutInitWindowSize를 통해 윈도우 창의 크기를 설정함
//
//각각의 가로세로 비율을 종횡비라고 부르는데
//이 2개의 종횡비를 일치시키는게 좋음
//그렇지 않다면 왜곡이 발생할수 있음

void myInit(void)
{
    glClearColor(1.0, 0.0, 0.0, 0.0); // 배경색을 빨간색으로 설정
    glColor3f(0.0f, 1.0f, 0.0f); // vertex나 polygon의 색상을 초록색으로 설정
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluOrtho2D(10.0, 630.0, 10.0, 470.0); // 가시공간 설정
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}
void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS); // 쿼드 공간을 설정
    glVertex3f(20.0, 20.0, 0.0); // 4개의 vertex로 쿼드를 설정함
    glVertex3f(20.0, 30.0, 0.0);
    glVertex3f(30.0, 30.0, 0.0);
    glVertex3f(30.0, 20.0, 0.0);
    glEnd();
    glFlush();
}
void main(int argc, char** argv)                                                           //
{
    glutInitWindowSize(640, 480); // 윈도우 창의 크기를 설정함
    glutInitWindowPosition(100, 150);
    glutCreateWindow("my first attempt");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();

    
}
