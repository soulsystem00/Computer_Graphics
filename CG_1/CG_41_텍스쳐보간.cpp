#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

// 텍스쳐가 물체에 입혀질 때 여러 옵션들이 발생할 수 있다.
// 이는 물체의 크기와 텍스쳐의 크기가 완전히 똑같지 않기 때문에 발생한다.
// 즉, 텍스쳐에서 여러개의 픽셀들이 물체에서는 하나의 픽셀로 결정이 되는 경우가 있을 것이다.
// 이러한 것을 어떻게 매핑을 시켜줄 것인지 결정을 해줄수가 있는데
// GL_LINEAR와 GL_NEAREST가 있다.

// GL_LINEAR는 쉽게 말해 픽셀들을 보간법을 거쳐 부드럽게 표현해주게 된다.
// 반대로 GL_NEAREST는 여러개의 픽셀에 있는 여러개의 색깔중 하나의 색으로 도형을 칠하게 된다.
// 이런 차이를 볼 수 있는 예시이다.




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