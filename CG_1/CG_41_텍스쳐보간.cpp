#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

// �ؽ��İ� ��ü�� ������ �� ���� �ɼǵ��� �߻��� �� �ִ�.
// �̴� ��ü�� ũ��� �ؽ����� ũ�Ⱑ ������ �Ȱ��� �ʱ� ������ �߻��Ѵ�.
// ��, �ؽ��Ŀ��� �������� �ȼ����� ��ü������ �ϳ��� �ȼ��� ������ �Ǵ� ��찡 ���� ���̴�.
// �̷��� ���� ��� ������ ������ ������ ������ ���ټ��� �ִµ�
// GL_LINEAR�� GL_NEAREST�� �ִ�.

// GL_LINEAR�� ���� ���� �ȼ����� �������� ���� �ε巴�� ǥ�����ְ� �ȴ�.
// �ݴ�� GL_NEAREST�� �������� �ȼ��� �ִ� �������� ������ �ϳ��� ������ ������ ĥ�ϰ� �ȴ�.
// �̷� ���̸� �� �� �ִ� �����̴�.




#define WIDTH   4
#define HEIGHT  4

GLubyte MyTexture[WIDTH][HEIGHT][3];

void FillMyTexture() {
    int s, t;
    for (s = 0; s < WIDTH; s++) {
        for (t = 0; t < HEIGHT; t++) {
            GLubyte Intensity = ((s + t) % 2) * 255;    //0�¥A�橡��?, 255�¥A��?��?
            MyTexture[s][t][0] = Intensity;             //Red ��ƨ?��??��O��c
            MyTexture[s][t][1] = 0;             //Green ��ƨ?��??��O��c
            MyTexture[s][t][2] = 0;             //Blue ��ƨ?��??��O��c
        }
    }
}

void MyInit() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    FillMyTexture();
    glTexImage2D(GL_TEXTURE_2D, 0, 3, WIDTH, HEIGHT, 0, GL_RGB,
        GL_UNSIGNED_BYTE, &MyTexture[0][0][0]);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    //glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glEnable(GL_TEXTURE_2D);
}

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -1.0, 0.0);
    glTexCoord2f(0.8, 0.2); glVertex3f(1.0, -1.0, 0.0);
    glTexCoord2f(0.6, 0.7); glVertex3f(0.0, 1.0, 0.0);
    glEnd();
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("openGL Sample Program");
    MyInit();
    glutDisplayFunc(MyDisplay);
    glutMainLoop();
    return 0;
}