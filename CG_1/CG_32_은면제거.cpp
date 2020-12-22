#include <GL/glut.h>
void drawScene(void)  
{
	  glClear(GL_COLOR_BUFFER_BIT);  
	  // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);    
	  // glEnable(GL_DEPTH_TEST);  
	  // Front faces filled, back faces outlined.   glPolygonMode(GL_FRONT, GL_FILL);   
	  glPolygonMode(GL_BACK, GL_LINE); 
	  glColor3f(1.0, 0.0, 0.0);
	  glBegin(GL_POLYGON); 
	  glVertex3f(5.0, 0.0, -10.0);  
	  glVertex3f(0.0, 5.0, -10.0);  
	  glEnd();  
	  glColor3f(0.0, 1.0, 0.0);   
	  glBegin(GL_POLYGON); 
	  glVertex3f(-5.0, 0.0, -15.0);  
	  glVertex3f(5.0, 0.0, -15.0); 
	  glVertex3f(0.0, 5.0, -15.0);  
	  glEnd();  
	  glFlush();   
}   
// Main routine.  
int main(int argc, char **argv)  
{
		40
		 