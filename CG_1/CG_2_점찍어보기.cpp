#include <GL/glut.h>

// 기본적인 점을 찍어보는 코드이다.
// glBegin(GL_POINTS) 를 이용하여 점을 찍는 것으로 설정을 한 후
// glVertex를 사용하여 점의 위치를 설정해준다.

void myInit(void) // 메인에서 호출되는 함수
{
	glClearColor(1.0, 1.0, 1.0, 0.0); // 배경색 정하기 (red, green, blue, alpha(투명도)) 
	glColor3f(0.0f, 0.0f, 0.0f); // vertex나 polygon의 색상을 설정, f가 붙었으니 매개변수는 float형
	glPointSize(4.0); // 점의 크기를 설정
	
	// 가시공간, 가시부피 설정 및 투영설정 - 추후 설명
	glMatrixMode(GL_PROJECTION);// set up appropriate matrices- to be explained
	glLoadIdentity();// to be explained
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);// to be explaine

}
void myDisplay(void) // 이벤트 발생 시 작동하는 함수
{
	glClear(GL_COLOR_BUFFER_BIT); // 윈도우 안의 각 픽셀의 컬러 버퍼 지우기(리셋을 의미)
	glBegin(GL_POINTS);
		glVertex2i(100, 50); // vertex를 이용하여 점을 찍음
		glVertex2i(100, 130);// i가 왔으니 매개변수는 정수형
		glVertex2i(150, 130);
	glEnd();
	
	glFlush(); // 일정 분량의 명령을 모아서 한번에 실행시켜주는 함수
	 
}
void main(int argc, char** argv)
{
	glutInitWindowSize(640, 480); // 윈도우 창의 크기를 설정 
	glutInitWindowPosition(100, 150); // 윈도우 창의 위치를 설정
	glutCreateWindow("my first attempt"); // 윈도우 창의 제목 설정
	glutDisplayFunc(myDisplay); // 이벤트 발생시 myDisplay라는 함수가 동작하도록 설정
	myInit();
	glutMainLoop(); // 메인 함수의 마지막에 오는 함수, 이벤트 처리 담당
}