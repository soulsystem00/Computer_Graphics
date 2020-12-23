#include <windows.h> // use proper includes for your system
#include <math.h>
#include <gl/Gl.h>
#include <gl/Glu.h>
#include <gl/Glut.h>

// 삼각함수를 이용하여 원을 그려본 예시이다.
// 원을 그릴 때 원의 방정식을 이용하여 좌표를 구할 수 있을 것이다.
// 다만 이러한 방식은 너무나도 복잡하다.
// 보다 간단한 방법은 삼각함수를 사용하면 된다. 
// x좌표는 cos으로
// y좌표는 sin을 사용하면 
// 각도에 따른 좌표를 구할 수 있게 된다. 
// 360도를 N개만큼 나누어 반복문을 돌려주면 
// 원을 그릴 수 있게 된다.

const int screenWidth = 400;	   // width of the screen window in pixels 
const int screenHeight = 400;	   // height of the screen window in pixels
#define PI 3.141592
#define TWOPI 2*3.14159265359

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);       // the background color is white
	glColor3f(0.0f, 0.0f, 0.0f);         // the drawing color is black 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-2.0, 2.0, -2.0, 2.0);

}
//<<<<<<<<<<<<<<<<<<<<<<<< myDisplay >>>>>>>>>>>>>>>>>
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);     // clear the screen 
	double t = 0;
	unsigned int N = 4000000;
	glBegin(GL_LINE_STRIP);
	for (t = 0; t <= 2 * PI; t += PI / N)
	{
		glVertex2f(cos(t), sin(t));
	}
	glEnd();
	glFlush();		   // send all output to display 
}
//<<<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>
void main(int argc, char** argv)
{
	glutInit(&argc, argv);          // initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set the display mode
	glutInitWindowSize(screenWidth, screenHeight); // set the window size
	glutInitWindowPosition(100, 150); // set the window position on screen
	glutCreateWindow("Dot Plot of a Function"); // open the screen window
	glutDisplayFunc(myDisplay);     // register the redraw function
	myInit();
	glutMainLoop(); 		     // go into a perpetual loop
}