#include <GL/glut.h>


//gluOrtho2D �� ���� ���ð����� ������
//glutInitWindowSize�� ���� ������ â�� ũ�⸦ ������
//
//������ ���μ��� ������ ��Ⱦ���� �θ��µ�
//�� 2���� ��Ⱦ�� ��ġ��Ű�°� ����
//�׷��� �ʴٸ� �ְ��� �߻��Ҽ� ����

void myInit(void)
{
    glClearColor(1.0, 0.0, 0.0, 0.0); // ������ ���������� ����
    glColor3f(0.0f, 1.0f, 0.0f); // vertex�� polygon�� ������ �ʷϻ����� ����
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluOrtho2D(10.0, 630.0, 10.0, 470.0); // ���ð��� ����
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}
void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS); // ���� ������ ����
    glVertex3f(20.0, 20.0, 0.0); // 4���� vertex�� ���带 ������
    glVertex3f(20.0, 30.0, 0.0);
    glVertex3f(30.0, 30.0, 0.0);
    glVertex3f(30.0, 20.0, 0.0);
    glEnd();
    glFlush();
}
void main(int argc, char** argv)                                                           //
{
    glutInitWindowSize(640, 480); // ������ â�� ũ�⸦ ������
    glutInitWindowPosition(100, 150);
    glutCreateWindow("my first attempt");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();

    
}
