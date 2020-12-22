#include <cstdlib>
#include <cmath>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <GL/glut.h>


using namespace std;

int numofpoint, numofpage;

vector<string> split(string str)
{
	vector<string> arr;
	string tmp;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != ' ')
		{
			tmp.push_back(str[i]);
		}
		else
		{
			arr.push_back(tmp);
			tmp.clear();
		}
	}
	arr.push_back(tmp);
	return arr;
}

typedef struct Point
{
	float x;
	float y;
	float z;
}point;

typedef struct Page
{
	int a;
	int b;
	int c;
}face;
vector<point> pointarray;
vector<face> pagearray;

void openfile(int* numofpoint, int* numofface) // vertex의 개수와 face의 개수를 받아오는 함수
{
	char tmp[100];
	string temp;
	ifstream ifile;
	ifile.open("block.off");
	ifile.getline(tmp, sizeof(tmp));
	ifile.getline(tmp, sizeof(tmp));
	temp = tmp;
	cout << temp << endl;
	vector<string> arr = split(temp);
	*numofpoint = stoi(arr[0]);
	*numofface = stoi(arr[1]);
	//printf("%d, %d\n", *numofpage, *numofpoint);
	ifile.close();
}

vector<point> scanpoint(int numofpoint) // 파일안의 vertex를 배열에 저장해주는 함수
{
	ifstream ifile;
	char tmp[100];
	string temp;
	point p;
	vector<point> parr;
	ifile.open("block.off");

	ifile.getline(tmp, sizeof(tmp));
	ifile.getline(tmp, sizeof(tmp));

	for (int i = 0; i < numofpoint; i++)
	{
		ifile.getline(tmp, sizeof(tmp));
		temp = tmp;
		vector<string> arr = split(temp);
		p.x = stof(arr[0]);
		p.y = stof(arr[1]);
		p.z = stof(arr[2]);
		parr.push_back(p);
	}
	//cout << parr[0].x << endl;
	//cout << parr[0].y << endl;
	//cout << parr[0].z << endl;
	//cout << parr[numofpoint-1].x << endl;
	//cout << parr[numofpoint-1].y << endl;
	//cout << parr[numofpoint-1].z << endl;
	ifile.close();
	return parr;
}

vector<face> scanpage(int numofpoint, int numofface) // face의 값을 배열에 저장해주는 함수
{
	ifstream ifile;
	char tmp[100];
	string temp;
	face p;
	vector<face> parr;
	ifile.open("block.off");

	ifile.getline(tmp, sizeof(tmp));
	ifile.getline(tmp, sizeof(tmp));

	for (int i = 0; i < numofpoint; i++)
	{
		ifile.getline(tmp, sizeof(tmp));
	}
	for (int i = 0; i < numofface; i++)
	{
		ifile.getline(tmp, sizeof(tmp));
		temp = tmp;
		vector<string> arr = split(temp);
		p.a = stof(arr[1]);
		p.b = stof(arr[2]);
		p.c = stof(arr[3]);
		parr.push_back(p);
	}
	ifile.close();
	return parr;
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glShadeModel(GL_FLAT);
    //glShadeModel(GL_SMOOTH);
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

    GLfloat material_ambient[] = { 0.1, 0.1, 0.1, 1.0 };  //
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

    //glutSolidTeapot(1.0);
    glutSolidSphere(15.0, 20, 16);

	//glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glLoadIdentity();
	gluLookAt(30.0, 30.0, 30.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); // 0 0 -10

	
	//for (int i = 0; i < numofpage; i++)
	//{
	//	glBegin(GL_POLYGON);
	//	int first = pagearray[i].a;
	//	int second = pagearray[i].b;
	//	int thrid = pagearray[i].c;

	//	glVertex3f(pointarray[first].x, pointarray[first].y, pointarray[first].z);
	//	glVertex3f(pointarray[second].x, pointarray[second].y, pointarray[second].z);
	//	glVertex3f(pointarray[thrid].x, pointarray[thrid].y, pointarray[thrid].z);

	//	glEnd();
	//}
	
    glFlush();
}


int main(int argc, char** argv)
{
	openfile(&numofpoint, &numofpage);
	pointarray = scanpoint(numofpoint);
	pagearray = scanpage(numofpoint, numofpage);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    glutDisplayFunc(display);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	glFrustum(-30.0, 30.0, -30.0, 30.0, 30.0, 100.0);
    //glOrtho(-2, 2, -2, 2, -1, 1);
    glutMainLoop();
    return 0;
}