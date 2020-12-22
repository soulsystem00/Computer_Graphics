#include <cstdlib>
#include <GL/glut.h>
#include <stdio.h>

void pickPixel(int x, int y)
{
    glPointSize(10.0f);
    glBegin(GL_POINTS);
    
    glVertex2i(x, y);
    glEnd();
}

int round(float z)
{
    int y;
    y = z > 0.0 ? int(z + 0.5) : int(z - 0.5);
    return y;
}

void DDA(int i1, int j1, int i2, int j2) // Assume i2 > i1.
{
    float y = j1;
    float m = float(j2 - j1) / (i2 - i1); // Assume -1 <= m <= 1.
    for (int x = i1; x <= i2; x++)
    {
        pickPixel(x, round(y));
        y += m;
    }
}

void MidpointLine(int x1, int y1, int x2, int y2) {
    int dx, dy, incrE, incrNE, D, x, y;
    dx = x2 - x1; dy = y2 - y1;
    D = 2 * dy - dx; //�������� ���� �ʱ�ȭ
    incrE = 2 * dy; //���� ȭ�� ���ý� ������
    incrNE = 2 * dy - 2 * dx; //������ ȭ�� ���ý� ������
    x = x1; y = y1; //ù ȭ��
    int count = 0;
    pickPixel(x, y); //ù ȭ�� �׸���
    while (x < x2) {
        printf("D = %d\n", D);
        if (D <= 0) { //���������� ����. ����ȭ�� ����
            D += incrE; //�������� ����
            x++; //���� ȭ�Ҵ� ����

        }
        else { //���������� ���. ������ ȭ�� ����
            D += incrNE; //�������� ����
            x++; y++; //���� ȭ�Ҵ� ������

        }
        count++;
        pickPixel(x, y); //ȭ�� �׸���

    }
    printf("�� �̿��� ������ �� = %d", count);

}

void drawScene(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 0.0);
    
    MidpointLine(0, 0, 9, 5);

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DDA.cpp");
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glutDisplayFunc(drawScene);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 11.0, -1.0, 11.0);
    glutMainLoop();

    return 0;
}

