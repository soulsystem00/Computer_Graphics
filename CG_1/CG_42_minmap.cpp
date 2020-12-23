#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
// 이번 예제는 텍스처에 색을 입혀보는 예제이다.
// 텍스쳐를 입히는데에는 여러 옵션들이 있따.
// GL_MODULATE는 도형의 색상과 텍스쳐의 색상을 곱하여 최종 색상을 만들게 된다.
// 반대로 GL_REPLACE는 도형의 위에 텍스쳐를 입히는 방식이다.

// 이러한 차이로 인하여 GL_MODULATE는 도형의 색상이 반영되는 반면
// GL_REPLACE는 도형의 색상이 반영되지 않는다.
#define WIDTH   4
#define HEIGHT  4

GLubyte MyTexture[WIDTH][HEIGHT][3];

void FillMyTexture() {
    int s, t;
    for (s = 0; s < WIDTH; s++) {
        for (t = 0; t < HEIGHT; t++) {
            GLubyte Intensity = ((s + t) % 2) * 255;    //0는쩇흑æ색?, 255는쩇백?색?
            MyTexture[s][t][0] = Intensity;             //Red 값튕?에??할O당쩭
            MyTexture[s][t][1] = Intensity;            //Green 값튕?에??할O당쩭
            MyTexture[s][t][2] = Intensity;             //Blue 값튕?에??할O당쩭
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
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(-1.0, -1.0, 0.0);
    glTexCoord2f(0.0, 1.0); glVertex3f(-1.0, 1.0, 0.0);
    glTexCoord2f(1.0, 1.0); glVertex3f(1.0, 1.0, 0.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(1.0, -1.0, 0.0);
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("openGL Sample Program");
    MyInit();
    glutDisplayFunc(MyDisplay);
    glutMainLoop();
    return 0;
}