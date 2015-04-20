#include <cmath>
#include <cstdlib>
#include <iostream>
#include <fstream>

#include <stdlib.h>
#include <GLUT/glut.h>
#include <OpenGL/glext.h>
#include <time.h>
#include <stdio.h>
#include <math.h>

using namespace std;

static int startTime;
static int endTime;
static int totalTime;

void setup(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    
}

void drawScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    gluLookAt (0.0, 4.0, 6.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    
    glColor3f(1,0,0);
    glutSolidCube(2);
    glFlush();
}

void printTime(void)
{
    totalTime = (endTime - startTime) / 1000;
    char numstr[21];
    sprintf(numstr, "%d", totalTime);
    string label = "Total Time (in seconds): ";
    string result = label + numstr;
    cout << result << endl;
}

void resize(int w, int h)
{
    glViewport (0, 0, w, h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (float)w/(float)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyInput(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 27:
            endTime = glutGet(GLUT_ELAPSED_TIME);
            printTime();
            exit(0);
            break;
        default:
            break;
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    startTime = glutGet(GLUT_ELAPSED_TIME);
   // glutInitContextVersion(2, 1);
   // glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
    
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100); 
    glutCreateWindow("Maze");
    
    glutDisplayFunc(drawScene); 
    glutReshapeFunc(resize);  
    glutKeyboardFunc(keyInput);
    
   // glewExperimental = GL_TRUE;
   // glewInit();
    setup();
    glutMainLoop(); 
}
