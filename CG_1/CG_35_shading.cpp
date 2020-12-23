#include <cstdlib>
#include <cmath>
#include <GL/glut.h>

// 물체에 광원을 적용시켰을 때
// 나타내는 방법에는 2가지가 있다.
// 첫번째로 Flat하게 나타내는 방법과
// smooth 하게 나타내는 방법이다.

// flat 하게 나타내는 방법은 
// 곡면에 대해 빛을 비추었을 때
// 곡면이 각지게 보여지게 된다.

// 반대로 smooth 하게 나타낸다면
// 곡면이 부드럽게 나타나게 된다.

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glShadeModel(GL_SMOOTH);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    GLfloat MyLightPosition[] = { 1.0, 2.0, 3.0, 1.0 };
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glLightfv(GL_LIGHT0, GL_POSITION, MyLightPosition);

    GLfloat MyLightAmbient[] = { 1.0, 1.0, 1.0, 1.0 }; //ambient = red
    GLfloat MyLightDiffuse[] = { 1.0, 1.0, 1.0, 1.0 }; // diffuse = yellow
    GLfloat MyLightSpecular[] = { 1.0, 1.0, 1.0, 1.0 }; // specular = white

    GLfloat material_ambient[] = { 0.1, 0.1, 0.1, 1.0 };  //¹?°??ö¡岬?Ã¼쬾¨??ù Æ㎖?¯?¼쬾º㎕?ù¨??
    GLfloat material_diffuse[] = { 1, 0, 0, 1.0 };
    GLfloat material_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat material_shininess[] = { 25.0 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);
    glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);
    glMaterialfv(GL_FRONT, GL_SHININESS, material_shininess);


    glLightfv(GL_LIGHT0, GL_AMBIENT, MyLightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, MyLightDiffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, MyLightSpecular);


    glutSolidSphere(1.0, 20, 16);
    glFlush();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    glutDisplayFunc(display);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2, 2, -2, 2, -1, 1);
    glutMainLoop();
    return 0;
}