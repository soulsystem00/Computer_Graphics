#include <cstdlib>
#include <cmath>
#include <iostream>
#include <GL/glut.h>

// 하나의 물체에 대해 여러개의 변환을 적용시켜보았다면
// 이제는 여러개의 물체에 대해 여러개의 변환을 적용시킨 예를 알아보자.

// 각 변환은 따로 처리를 하지 않는 이상
// 계속해서 영향을 미치게 된다.

// 만일 첫번째 그리는 물체에 대해 회전을 시켜주었다면
// 따로 처리를 해주지 않으면 두번째 그리는 물체에도 똑같이 회전이 적용된다.

// 그렇기 때문에 각각 다른 변환을 주고 싶어도 
// 따로 처리하지 않으면 이전 변환이 물체에 영향을 주어
// 원하지 않는 결과나 나올 수 있다.

void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);       // the background color is white
    glColor3f(1.0f, 0.0f, 0.0f);         // the drawing color is black 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 50.0);
}

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();               // 행렬의 초기화, 단위행렬 I
    glTranslatef(0.0, 0.0, -15.0);  // T1,          CTM = T1
    glTranslatef(5, 0, 0);          // T2,          CTM = T1 * T2
    glutWireCube(5.0);              // V1,          T1 * (T2 * V1 )    
    glTranslatef(0, 10, 0);         // T3           CTM = T1 * T2 * T3
    glutWireSphere(2.0, 10, 8);     // V2           T1 * T2 * ( T3 * V2 ) 
    // 결론적으로 물체를 여러개 변환을 해주면 이전의 변환이 모든 물체에 영향을 미친다.
    glFlush();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("box.cpp");
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glutDisplayFunc(drawScene);
    myInit();

    glutMainLoop();
    return 0;
}