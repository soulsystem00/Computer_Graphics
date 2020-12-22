#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#define WIDTH   4
#define HEIGHT  4

GLubyte MyTexture[WIDTH][HEIGHT][3];

void FillMyTexture() {
    int s, t;
    for (s = 0; s < WIDTH; s++) {
        for (t = 0; t < HEIGHT; t++) {
            GLubyte Intensity = ((s + t) % 2) * 255;    //0´Â¥AÈæ©¡»ö?, 255´Â¥A¹é?»ö?
            MyTexture[s][t][0] = Intensity;             //Red °ªÆ¨?¿¡??ÇÒO´ç¥c
            MyTexture[s][t][1] = Intensity;            //Green °ªÆ¨?¿¡??ÇÒO´ç¥c
            MyTexture[s][t][2] = Intensity;             //Blue °ªÆ¨?¿¡??ÇÒO´ç¥c
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
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
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