#include <cmath>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <GL/glut.h>
using namespace std;

// 이번 예시는 텍스쳐에 광원 효과까지 넣어본 예시이다.

#define PI 3.14159265358979324

// Globals.
static unsigned int texture[2]; // Array of texture indices.
static float d = 1.0; // Intensity of sun light.
static float theta = 45.0; // Angle of the sun with the ground.

struct BitMapFile
{
    int sizeX;
    int sizeY;
    unsigned char* data;
};

BitMapFile* getBMPData(string filename)
{
    BitMapFile* bmp = new BitMapFile;
    unsigned int size, offset, headerSize;

    // Read input file name.
    ifstream infile(filename.c_str(), ios::binary);

    // Get the starting point of the image data.
    infile.seekg(10);
    infile.read((char*)&offset, 4);

    // Get the header size of the bitmap.
    infile.read((char*)&headerSize, 4);

    // Get width and height values in the bitmap header.
    infile.seekg(18);
    infile.read((char*)&bmp->sizeX, 4);
    infile.read((char*)&bmp->sizeY, 4);

    // Allocate buffer for the image.
    size = bmp->sizeX * bmp->sizeY * 24;
    bmp->data = new unsigned char[size];

    // Read bitmap data.
    infile.seekg(offset);
    infile.read((char*)bmp->data, size);

    // Reverse color from bgr to rgb.
    int temp;
    for (int i = 0; i < size; i += 3)
    {
        temp = bmp->data[i];
        bmp->data[i] = bmp->data[i + 2];
        bmp->data[i + 2] = temp;
    }

    return bmp;
}


// Load external textures.
void loadExternalTextures()
{
    // Local storage for bmp image data.
    BitMapFile* image[2];

    // Load the images.
    image[0] = getBMPData("Textures/grass.bmp");
    image[1] = getBMPData("Textures/sky.bmp");

    // Bind grass image to texture object texture[0]. 
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image[0]->sizeX, image[0]->sizeY, 0,
        GL_RGB, GL_UNSIGNED_BYTE, image[0]->data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    // Bind sky image to texture object texture[1]
    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image[1]->sizeX, image[1]->sizeY, 0,
        GL_RGB, GL_UNSIGNED_BYTE, image[1]->data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}

// Initialization routine.
void setup(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);

    // Turn on OpenGL lighting.
    glEnable(GL_LIGHTING);

    // Light property vectors that are constant.
    float lightAmb[] = { 0.0, 0.0, 0.0, 1.0 };
    float globAmb[] = { 0.2, 0.2, 0.2, 1.0 };

    // Light properties.
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);

    glEnable(GL_LIGHT0); // Enable particular light source.
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globAmb); // Global ambient light.

     // Material property vectors.
    float matAmbAndDif[] = { 1.0, 1.0, 1.0, 1.0 };
    float matSpec[] = { 1.0, 1.0, 1.0, 1.0 };
    float matShine[] = { 50.0 };

    // Material properties.
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, matAmbAndDif);
    glMaterialfv(GL_FRONT, GL_SPECULAR, matSpec);
    glMaterialfv(GL_FRONT, GL_SHININESS, matShine);

    // Create texture ids. 
    glGenTextures(2, texture);

    // Load external textures.
    loadExternalTextures();

    // Specify how texture values combine with current surface color values.
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    // Turn on OpenGL texturing.
    glEnable(GL_TEXTURE_2D);

    // Cull back faces.
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
}

// Drawing routine.
void drawScene(void)
{
    // Light property vectors that change during runtime.
    float lightDifAndSpec[] = { d, d, d, 1.0 };
    float lightPos[] = { cos((PI / 180.0) * theta), sin((PI / 180.0) * theta), 0.0, 0.0 };

    // Light properties.
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDifAndSpec);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightDifAndSpec);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    gluLookAt(0.0, 10.0, 15.0, 0.0, 10.0, 0.0, 0.0, 1.0, 0.0);

    // Map the grass texture onto a rectangle lying along the xz-plane.
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 0.0);
    glNormal3f(0.0, 1.0, 0.0);
    glTexCoord2f(0.0, 0.0); glVertex3f(-100.0, 0.0, 100.0);
    glTexCoord2f(8.0, 0.0); glVertex3f(100.0, 0.0, 100.0);
    glTexCoord2f(8.0, 8.0); glVertex3f(100.0, 0.0, -100.0);
    glTexCoord2f(0.0, 8.0); glVertex3f(-100.0, 0.0, -100.0);
    glEnd();

    // Map the sky texture onto a rectangle parallel to the xy-plane.
    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glNormal3f(0.0, 1.0, 0.0);
    glTexCoord2f(0.0, 0.0); glVertex3f(-100.0, 0.0, -70.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(100.0, 0.0, -70.0);
    glTexCoord2f(1.0, 1.0); glVertex3f(100.0, 120.0, -70.0);
    glTexCoord2f(0.0, 1.0); glVertex3f(-100.0, 120.0, -70.0);
    glEnd();

    // Draw a white line in the direction of the sun after disabling lighting and texturing.
    glDisable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);

    glColor3f(1.0, 1.0, 1.0);
    glLoadIdentity();
    glBegin(GL_LINES);
    glVertex3f(0.0, 0.0, -6.0);
    glVertex3f(d * cos((PI / 180.0) * theta), d * sin((PI / 180.0) * theta), -6.0);
    glEnd();

    glEnable(GL_TEXTURE_2D); // Restore texturing. 
    glEnable(GL_LIGHTING); // Restore lighting.

    glutSwapBuffers();
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        exit(0);
        break;
    default:
        break;
    }
}

// Callback routine for non-ASCII key entry.
void specialKeyInput(int key, int x, int y)
{
    if (key == GLUT_KEY_DOWN)
    {
        if (d > 0.0) d -= 0.05;
    }
    if (key == GLUT_KEY_UP)
    {
        if (d < 1.0) d += 0.05;
    }
    if (key == GLUT_KEY_RIGHT)
    {
        if (theta > 0.0) theta -= 1.0;
    }
    if (key == GLUT_KEY_LEFT)
    {
        if (theta < 180.0) theta += 1.0;
    }
    glutPostRedisplay();
}

// Routine to output interaction instructions to the C++ window.
void printInteraction(void)
{
    cout << "Interaction:" << endl;
    cout << "Press the left and right arrow keys to change the direction of the sun." << endl
        << "Press the up and down keys to change the sunlight intensity." << endl;
}

// Main routine.
int main(int argc, char** argv)
{
    printInteraction();
    glutInit(&argc, argv);


    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("fieldAndSkyLit.cpp");
    glutDisplayFunc(drawScene);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyInput);
    glutSpecialFunc(specialKeyInput);

    setup();

    glutMainLoop();
}