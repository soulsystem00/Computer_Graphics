#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>


// 이번 예제는 도형에 텍스쳐를 입혀보는 예제이다.
// 텍스쳐를 입히는데에는 여러 방법이 있다.
// 그 중 기초적인 방법이 
// 각 vertex에 텍스처의 좌표를 매핑시켜주는 방법이다.
// 이러한 방법을 통하여 텍스처에서 어느 부분을 도형에 입힐 것인지 결정할 수 있다.
// 다만 설정한 좌표에 대해 비율이 같지 않을 경우 왜곡이 발생할 수 있다.


#define WIDTH   4
#define HEIGHT  4

GLubyte MyTexture[WIDTH][HEIGHT][3];

void FillMyTexture() {
    int s, t;
    for (s = 0; s < WIDTH; s++) {
        for (t = 0; t < HEIGHT; t++) {
            GLubyte Intensity = ((s + t) % 2) * 255;    //0는쩇흑æ색?, 255는쩇백?색?
            MyTexture[s][t][0] = Intensity;             //Red 값튕?에??할O당쩭
            MyTexture[s][t][1] = 0;             //Green 값튕?에??할O당쩭
            MyTexture[s][t][2] = 0;             //Blue 값튕?에??할O당쩭
        }
    }
}

void MyInit() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    FillMyTexture();
    glTexImage2D(GL_TEXTURE_2D, 0, 3, WIDTH, HEIGHT, 0, GL_RGB,
        GL_UNSIGNED_BYTE, &MyTexture[0][0][0]);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glEnable(GL_TEXTURE_2D);
}

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    //glBegin(GL_QUADS);
    //glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -1.0, 0.0);
    //glTexCoord2f(0.0, 1.0); glVertex3f(-1.0, 1.0, 0.0);
    //glTexCoord2f(1.0, 1.0); glVertex3f(1.0, 1.0, 0.0);
    //glTexCoord2f(1.0, 0.0); glVertex3f(1.0, -1.0, 0.0);
    glBegin(GL_POLYGON);
    glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -1.0, 0.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(1.0, -1.0, 0.0);
    glTexCoord2f(0.5, 1.0); glVertex3f(0, 1.0, 0.0);
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