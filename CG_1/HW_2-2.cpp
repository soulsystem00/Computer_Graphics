#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <fstream>

#define PI 3.141592

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
	glTranslatef(320, 240, 0);
	glScalef(0.1, 0.1, 0.1);
	
	int r = 1000;
	int x = 1;
	int N = 12;
	for (double i = 0; i <= 2 * PI; i += (2 * PI) / N)
	{
		glPushMatrix();
		glTranslatef(r * cos(i), r * sin(i), 0);
		glRotated(30 * x - 140, 0, 0, 1);
		drawPolyLineFile("dino.dat");		// draw it again
		glPopMatrix();
		x += 1;
	}

	//double t = 0;
	//double N = 12;

	//for (t = 0; t <= 2 * PI; t += 2 * PI / N)
	//{
	//	glTranslatef(cos(t), sin(t), 0);
	//	drawPolyLineFile("dino.dat");		// draw it again
	//}
	//glRotated(0, 0, 0, 1);
	
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