#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <fstream>

// ViewPort를 활용하여 여러개의 그림을 그리는 예시이다.
// 기존의 Dino 그림을 화면을 분할하여 그리게 된다. 

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
	//glViewport(0, 0, 320, 240);
	//drawPolyLineFile("dino.dat");		// draw it again
	//glViewport(320, 0, 320, 240);
	//drawPolyLineFile("dino.dat");
	//glViewport(0, 240, 320, 240);
	//drawPolyLineFile("dino.dat");
	//glViewport(320, 240, 320, 240);
	//drawPolyLineFile("dino.dat");
	int n = 4;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			glViewport(i*(640/n), j*(480/n), 640/n, 480/n);
			drawPolyLineFile("dino.dat");
		}
	}
	glFlush();

}

void render2() {

	glClear(GL_COLOR_BUFFER_BIT);
	setWindow(0, 640.0, 0, 480.0);		// set a fixed window
	glViewport(320, 0, 320, 480);
	drawPolyLineFile("dino.dat");		// draw it again
	glFlush();

}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Poly Line Demo o_O");
	glutDisplayFunc(render);
	//glutDisplayFunc(render2);
	glutMainLoop();
	return(0);

}