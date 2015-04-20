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
static char theStringBuffer[10]; // String buffer.
static long font = (long)GLUT_BITMAP_8_BY_13; // Font selection.
static int score = 1000000;
static bool done = false;

// Routine to draw a bitmap character string.
void writeBitmapString(void *font, char *string)
{
    char *c;
    
    for (c = string; *c != '\0'; c++) glutBitmapCharacter(font, *c);
}

// Routine to convert floating point to char string.
void floatToString(char * destStr, int precision, float val)
{
    sprintf(destStr,"%f",val);
    destStr[precision] = '\0';
}
void setup(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    
}

void drawScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    
    glColor3f(0.0, 0.0, 0.0);
    floatToString(theStringBuffer, 4, glutGet(GLUT_ELAPSED_TIME)/1000);
    glRasterPos3f(0.0, -1.0, -2.0);
    writeBitmapString((void*)font, "Time (in seconds): ");
    writeBitmapString((void*)font, theStringBuffer);
    glutPostRedisplay();
    
    gluLookAt (0.0, 4.0, 6.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    
    glColor3f(1,0,0);
    glutSolidCube(2);
    glFlush();
}

void Timer(int value) {
    glutTimerFunc(33, Timer, 0);
    glutPostRedisplay();
}

void printScore(void)
{
    totalTime = (endTime - startTime);
    score = score - totalTime;
    char numstr1[21];
    sprintf(numstr1, "%d", score);
    string label1 = "Score: ";
    string result1 = label1 + numstr1;
    cout << result1 << endl;
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

void gameOver(void)
{
    if(done){
        endTime = glutGet(GLUT_ELAPSED_TIME);
        printScore();
    }
}

void keyInput(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 27:
            endTime = glutGet(GLUT_ELAPSED_TIME);
            //printTime();
            printScore();
            exit(0);
            break;
        case 'g':
            score -= 1000;
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
    Timer(0);
    glutMainLoop();
}