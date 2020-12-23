#include <GL/glut.h>

// ���������� �����̴�.
// ���ð����� 3D�� ���Ұ�,
// �� Vertex�� z��ǥ�� 0���� ���Ҵ�.
// �̶� ���ð����� Viewing face�� -1������
// z��ǥ�� 0�� �׸��� ���������� �������� ���� Ȯ�� �� �� �־���.


void Display() 
{   
      glClear(GL_COLOR_BUFFER_BIT);   
      glColor3f(0.0, 1.0, 0.0);   
      glBegin(GL_QUADS);   
      glVertex3f(10, 10, 0.0);   
      glVertex3f(20, 10, 0.0);   
      glVertex3f(20, 20, 0);   
      glVertex3f(10, 20, 0);   
      glEnd();   
      glFlush();   
}   
int main()
{
    glutInitWindowSize(200, 200);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL Hello World!");
    glClearColor(1.0, 0.0, 0.0, 0.0);
    glOrtho(0, 100, 0, 100, -1, 1); //orthogonal projection   
    glutDisplayFunc(Display);
    glutMainLoop();
    return 0;
}