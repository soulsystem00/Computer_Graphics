#include <GL/glut.h>

void Display() 
{  
	glClear(GL_COLOR_BUFFER_BIT);  
	glColor3f(0.0, 1.0, 0.0);  
	glBegin(GL_QUADS);  
	glVertex3f(-20, -20, 0);  
	glVertex3f(80, 20, 0);  
	glVertex3f(120, 120, 0); 
	glVertex3f(20, 80, 0); 
	glEnd(); 
	glFlush();  
}  
int main() 
{
	glutInitWindowSize(200, 200); 
	glutInitWindowPosition(100, 100); 
	glutCreateWindow("OpenGL Hello World!");
	glClearColor(1.0, 0.0, 0.0, 0.0);
	glOrtho(0, 200, 0, 200, -1, 1);//orthogonal projection  
	glutDisplayFunc(Display); 
	glutMainLoop(); 
	return 0; 
}
