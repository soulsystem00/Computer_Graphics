#include <math.h>
#include <GL/glut.h>

// 이번 예시는 도형의 내부를 채우는 알고리즘에 관한 예시이다.
// 도형의 내부를 채울때 여러 방법이 있겠지만
// 가장 기본적인 방법은 한 점을 시작으로
// 상,하,좌,우를 방문하여 채우는 방식이다.
// 이것을 순환적으로 사용하면 도형의 내부가 채워지게 된다.


struct Point {
	GLint x;
	GLint y;
};

struct Color {
	GLfloat r;
	GLfloat g;
	GLfloat b;
};

void init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 480);
}

Color getPixelColor(GLint x, GLint y) {
	Color color;
	glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &color);
	return color;
}

void setPixelColor(GLint x, GLint y, Color color) {
	glColor3f(color.r, color.g, color.b);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}

void floodFill(GLint x, GLint y, Color oldColor, Color newColor) {
	Color color;
	color = getPixelColor(x, y);

	if (color.r == oldColor.r && color.g == oldColor.g && color.b == oldColor.b)
	{
		setPixelColor(x, y, newColor);
		floodFill(x + 1, y, oldColor, newColor);
		floodFill(x, y + 1, oldColor, newColor);
		floodFill(x - 1, y, oldColor, newColor);
		floodFill(x, y - 1, oldColor, newColor);
	}
	return;
}

void onMouseClick(int button, int state, int x, int y)
{
	Color newColor = { 1.0f, 0.0f, 0.0f };
	Color oldColor = { 1.0f, 1.0f, 1.0f };

	floodFill(320, 240, oldColor, newColor);
}

void draw_circle(Point pC, GLfloat radius) {
	GLfloat step = 1 / radius;
	GLfloat x, y;

	for (GLfloat theta = 0; theta <= 360; theta += step) {
		x = pC.x + (radius * cos(theta));
		y = pC.y + (radius * sin(theta));
		glVertex2i(x, y);
	}
}

void display(void) {
	Point pt = { 320, 240 };
	GLfloat radius = 20;

	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	draw_circle(pt, radius);
	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Open GL");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(onMouseClick);
	glutMainLoop();
	return 0;
}