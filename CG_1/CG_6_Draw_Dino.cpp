#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <fstream>

// Vertex의 정보는 코드에 직접 기입할 수도 있지만
// 파일에 저장되어있는 것을 불러와 사용할 수도 있다.
// 보다 복잡한 그림의 경우에는 파일에 저장되어 있는 것을 사용한다.  
// 이렇게 파일에서 그림을 불러와 복잡한 그림을 그리는 예시이다.  


void drawPolyLineFile(const char* fileName) {

	std::ifstream inStream;
	inStream.open(fileName);	// open the file
	if (inStream.fail())
		return;
	//glClear(GL_COLOR_BUFFER_BIT);      // clear the screen 
	GLint numpolys, numLines, x, y;
	inStream >> numpolys;		           // read the number of polylines
	for (int j = 0; j < numpolys; j++)  // read each polyline
	{
		inStream >> numLines;
		glBegin(GL_LINE_STRIP);	     // draw the next polyline
		for (int i = 0; i < numLines; i++)
		{
			inStream >> x >> y;        // read the next x, y pair
			glVertex2i(x, y);
		}
		glEnd();
	}
	glFlush();
	inStream.close();
}

//--------------- setWindow ---------------------
void setWindow(float left, float right, int bottom, int top)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(left, right, bottom, top);
}

void render() {

	glClear(GL_COLOR_BUFFER_BIT);
	setWindow(0, 640.0, 0, 480.0);		// set a fixed window
	drawPolyLineFile("dino.dat");		// draw it again
	glFlush();

}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Poly Line Demo o_O");
	glutDisplayFunc(render);;
	glutMainLoop();
	return(0);

}