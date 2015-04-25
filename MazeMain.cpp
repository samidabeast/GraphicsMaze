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

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

static int isCollision = 0;

#define double M_PI = 3.14159265;

enum ObjType { CUBE };

typedef struct
{
    ObjType type;
    
    float x;
    float y;
    float z;
    
} object;


static object objects[] =
{
    { CUBE, -97, 0, -40 },
    { CUBE, -97, 0, -46 },
    { CUBE, -97, 0, -52 },
    { CUBE, -97, 0, -58 },
    { CUBE, -97, 0, -64 },
    { CUBE, -97, 0, -70 },
    { CUBE, -97, 0, -76 },
    { CUBE, -97, 0, -82 },
    { CUBE, -97, 0, -88 },
    { CUBE, -97, 0, -94 },
    { CUBE, 0, 0, 0 }, //e
    { CUBE, -91, 0, -40 },
    { CUBE, -91, 0, -46 },
    { CUBE, -91, 0, -52 },
    { CUBE, -91, 0, -58 },
    { CUBE, -91, 0, -64 },
    { CUBE, -91, 0, -70 },
    { CUBE, -91, 0, -76 },
    { CUBE, -91, 0, -82 },
    { CUBE, -91, 0, -88 },
    { CUBE, -91, 0, -94 },
    { CUBE, 0, 0, 0 }, //e
    { CUBE, -85, 0, -40 },
    { CUBE, -85, 0, -46 },
    { CUBE, -85, 0, -52 },
    { CUBE, -85, 0, -58 },
    { CUBE, -85, 0, -64 },
    { CUBE, -85, 0, -70 },
    { CUBE, -85, 0, -76 },
    { CUBE, -85, 0, -82 },
    { CUBE, -85, 0, -88 },
    { CUBE, -85, 0, -94 },
    { CUBE, 0, 0, 0 }, //e
    { CUBE, -79, 0, -40 },
    { CUBE, -79, 0, -46 },
    { CUBE, -79, 0, -52 },
    { CUBE, -79, 0, -58 },
    { CUBE, -79, 0, -64 },
    { CUBE, -79, 0, -70 },
    { CUBE, -79, 0, -76 },
    { CUBE, -79, 0, -82 },
    { CUBE, -79, 0, -88 },
    { CUBE, -79, 0, -94 },
    { CUBE, 0, 0, 0 }, //e
    { CUBE, -73, 0, -40 },
    { CUBE, -73, 0, -46 },
    { CUBE, -73, 0, -52 },
    { CUBE, -73, 0, -58 },
    { CUBE, -73, 0, -64 },
    { CUBE, -73, 0, -70 },
    { CUBE, -73, 0, -76 },
    { CUBE, -73, 0, -82 },
    { CUBE, -73, 0, -88 },
    { CUBE, -73, 0, -94 },
    { CUBE, 0, 0, 0 }, //e
    { CUBE, -67, 0, -40 },
    { CUBE, -67, 0, -46 },
    { CUBE, -67, 0, -52 },
    { CUBE, -67, 0, -58 },
    { CUBE, -67, 0, -64 },
    { CUBE, -67, 0, -70 },
    { CUBE, -67, 0, -76 },
    { CUBE, -67, 0, -82 },
    { CUBE, -67, 0, -88 },
    { CUBE, -67, 0, -94 },
    { CUBE, 0, 0, 0 }, //e
    { CUBE, -61, 0, -40 },
    { CUBE, -61, 0, -46 },
    { CUBE, -61, 0, -52 },
    { CUBE, -61, 0, -58 },
    { CUBE, -61, 0, -64 },
    { CUBE, -61, 0, -70 },
    { CUBE, -61, 0, -76 },
    { CUBE, -61, 0, -82 },
    { CUBE, -61, 0, -88 },
    { CUBE, -61, 0, -94 },
    { CUBE, 0, 0, 0 }, //e
    { CUBE, -55, 0, -40 },
    { CUBE, -55, 0, -46 },
    { CUBE, -55, 0, -52 },
    { CUBE, -55, 0, -58 },
    { CUBE, -55, 0, -64 },
    { CUBE, -55, 0, -70 },
    { CUBE, -55, 0, -76 },
    { CUBE, -55, 0, -82 },
    { CUBE, -55, 0, -88 },
    { CUBE, -55, 0, -94 },
    { CUBE, 0, 0, 0 }, //e
    { CUBE, -49, 0, -40 },
    { CUBE, -49, 0, -46 },
    { CUBE, -49, 0, -52 },
    { CUBE, -49, 0, -58 },
    { CUBE, -49, 0, -64 },
    { CUBE, -49, 0, -70 },
    { CUBE, -49, 0, -76 },
    { CUBE, -49, 0, -82 },
    { CUBE, -49, 0, -88 },
    { CUBE, -49, 0, -94 },
    { CUBE, 0, 0, 0 }, //e
    { CUBE, -43, 0, -40 },
    { CUBE, -43, 0, -46 },
    { CUBE, -43, 0, -52 },
    { CUBE, -43, 0, -58 },
    { CUBE, -43, 0, -64 },
    { CUBE, -43, 0, -70 },
    { CUBE, -43, 0, -76 },
    { CUBE, -43, 0, -82 },
    { CUBE, -43, 0, -88 },
    { CUBE, -43, 0, -94 },
    { CUBE, 0, 0, 0 }, //e
    { CUBE, -37, 0, -40 },
    { CUBE, -37, 0, -46 },
    { CUBE, -37, 0, -52 },
    { CUBE, -37, 0, -58 },
    { CUBE, -37, 0, -64 },
    { CUBE, -37, 0, -70 },
    { CUBE, -37, 0, -76 },
    { CUBE, -37, 0, -82 },
    { CUBE, -37, 0, -88 },
    { CUBE, -37, 0, -94 },
    { CUBE, 0, 0, 0 }, //e
    { CUBE, -31, 0, -40 },
    { CUBE, -31, 0, -46 },
    { CUBE, -31, 0, -52 },
    { CUBE, -31, 0, -58 },
    { CUBE, -31, 0, -64 },
    { CUBE, -31, 0, -70 },
    { CUBE, -31, 0, -76 },
    { CUBE, -31, 0, -82 },
    { CUBE, -31, 0, -88 },
    { CUBE, -31, 0, -94 },
    { CUBE, 0, 0, 0 }, //e
};
// this array holds the center locations of each cube
static int objs[] = {
    -97, -40,
    -97, -46,
    -97, -52,
    -97, -58,
    -97, -64,
    -97, -70,
    -97, -76,
    -97, -82,
    -97, -88,
    -97, -94,
    0, 0,
    -91, -40,
    -91, -46,
    -91, -52,
    -91, -58,
    -91, -64,
    -91, -70,
    -91, -76,
    -91, -82,
    -91, -88,
    -91, -94,
    0, 0,
    -85, -40,
    -85, -46,
    -85, -52,
    -85, -58,
    -85, -64,
    -85, -70,
    -85, -76,
    -85, -82,
    -85, -88,
    -85, -94,
    0, 0,
    -79, -40,
    -79, -46,
    -79, -52,
    -79, -58,
    -79, -64,
    -79, -70,
    -79, -76,
    -79, -82,
    -79, -88,
    -79, -94,
    0, 0,
    -73, -40,
    -73, -46,
    -73, -52,
    -73, -58,
    -73, -64,
    -73, -70,
    -73, -76,
    -73, -82,
    -73, -88,
    -73, -94,
    0, 0,
    -67, -40,
    -67, -46,
    -67, -52,
    -67, -58,
    -67, -64,
    -67, -70,
    -67, -76,
    -67, -82,
    -67, -88,
    -67, -94,
    0, 0,
    -61, -40,
    -61, -46,
    -61, -52,
    -61, -58,
    -61, -64,
    -61, -70,
    -61, -76,
    -61, -82,
    -61, -88,
    -61, -94,
    0, 0,
    -55, -40,
    -55, -46,
    -55, -52,
    -55, -58,
    -55, -64,
    -55, -70,
    -55, -76,
    -55, -82,
    -55, -88,
    -55, -94,
    0, 0,
    -49, -40,
    -49, -46,
    -49, -52,
    -49, -58,
    -49, -64,
    -49, -70,
    -49, -76,
    -49, -82,
    -49, -88,
    -49, -94,
    0, 0,
    -43, -40,
    -43, -46,
    -43, -52,
    -43, -58,
    -43, -64,
    -43, -70,
    -43, -76,
    -43, -82,
    -43, -88,
    -43, -94,
    0, 0,
    -37, -40,
    -37, -46,
    -37, -52,
    -37, -58,
    -37, -64,
    -37, -70,
    -37, -76,
    -37, -82,
    -37, -88,
    -37, -94,
    0, 0,
    -31, -40,
    -31, -46,
    -31, -52,
    -31, -58,
    -31, -64,
    -31, -70,
    -31, -76,
    -31, -82,
    -31, -88,
    -31, -94,
    0, 0 };



static float my_x = -34;
static float my_y = 0;
static float my_z = -49;
static float my_angle = 0;
static float up_down_angle = 0;

static int window_width;
static int window_height;
static int last_mouse_x;
static int last_mouse_y;

int n;
char output[132];

static int startTime;
static int endTime;
static int totalTime;
static char theStringBuffer[10]; // String buffer.
static long font = (long)GLUT_BITMAP_8_BY_13; // Font selection.
static int score = 1000000;
static bool done = false;

static float lightPos[] = { my_x, my_y, my_z, 1.0 };
static float spotDirection[] = { my_x, my_y, my_z }; // Spotlight direction.
static float spotExponent = 0.0; // Spotlight exponent = attenuation factor
static float spotAngle = 5.0; // Spotlight cone half-angle.


//this array holds the locations of the cubes that are drawn in the map
static int cubeLoc[600];
//this takes the values of the camera and checks with nearby cubes to check for intersection
int checkSpheresIntersection(float x1, float y1, float z1, float r1,
                             float x2, float y2, float z2, float r2)
{
    //cout << sqrt(((x1 - x2)*(x1 - x2))+ ((z1 - z2)*(z1 - z2))) << endl;
    
    return (sqrt((x1 - x2)*(x1 - x2) + (z1 - z2)*(z1 - z2)) <= (r2 ));
}
//this takes the values of the current camera location and checks for collision
int objectCollision(float x, float z, float a)
{
    int i;
    
    float camx = x;
    float camz = z;
    float camangle = a;
    
    int arrCount = sizeof(objs) / sizeof(objs[0]);
    
    for (i = 0; i < arrCount; i +=2)
    {
        if ((cubeLoc[i] >(camx - 4) && cubeLoc[i] < (camx + 4)) && (cubeLoc[i + 1] > (camz - 4) && cubeLoc[i + 1] < (camz + 4)))
        {
            //cout << "camx and camz" << camx << camz << endl;
            //cout << "objsi and objsi+1" << cubeLoc[i] << cubeLoc[i + 1] << endl;
            if (checkSpheresIntersection(camx , 0.0, camz , 1,
                                         cubeLoc[i], 0, cubeLoc[i + 1], 3.3)){
                score -= 500;
                cout << "Wall hit" << endl;
                return 1;
                
            }
        }
        
    }
    return 0;
}


void drawObject(const object& o)
{
    glPushMatrix();
    glTranslatef(o.x, o.y, o.z);
    glLineWidth(1);
    
    switch (o.type)
    {
        case CUBE:
            //cube front
            glBegin(GL_TRIANGLES);
            glTexCoord2f(0, 0); glVertex3f(-3, -3, 3);
            glTexCoord2f(1, 0); glVertex3f(3, -3, 3);
            glTexCoord2f(1, 1); glVertex3f(3, 3, 3);
            
            glTexCoord2f(1, 1); glVertex3f(3, 3, 3);
            glTexCoord2f(0, 1); glVertex3f(-3, 3, 3);
            glTexCoord2f(0, 0); glVertex3f(-3, -3, 3);
            glEnd();
            
            //cube right
            glBegin(GL_TRIANGLES);
            glTexCoord2f(0, 0); glVertex3f(3.0, -3.0, 3.0);
            glTexCoord2f(1, 0); glVertex3f(3, -3, -3);
            glTexCoord2f(1, 1); glVertex3f(3, 3, -3);
            
            glTexCoord2f(1, 1); glVertex3f(3, 3, -3);
            glTexCoord2f(0, 1); glVertex3f(3, 3, 3);
            glTexCoord2f(0, 0); glVertex3f(3, -3, 3);
            glEnd();
            
            //cube left
            glBegin(GL_TRIANGLES);
            glTexCoord2f(0, 0); glVertex3f(-3, -3, 3);
            glTexCoord2f(1, 0); glVertex3f(-3, -3, -3);
            glTexCoord2f(1, 1); glVertex3f(-3, 3, -3);
            
            glTexCoord2f(1, 1); glVertex3f(-3, 3, -3);
            glTexCoord2f(0, 1); glVertex3f(-3, 3, 3);
            glTexCoord2f(0, 0); glVertex3f(-3, -3, 3);
            glEnd();
            
            //cube back
            glBegin(GL_TRIANGLES);
            glTexCoord2f(0, 0); glVertex3f(-3, -3, -3);
            glTexCoord2f(1, 0); glVertex3f(3, -3, -3);
            glTexCoord2f(1, 1); glVertex3f(3, 3, -3);
            
            glTexCoord2f(1, 1); glVertex3f(3, 3, -3);
            glTexCoord2f(0, 1); glVertex3f(-3, 3, -3);
            glTexCoord2f(0, 0); glVertex3f(-3, -3, -3);
            glEnd();
            
            //cube top
            glBegin(GL_TRIANGLES);
            glTexCoord2f(0, 0); glVertex3f(-3, 3, 3);
            glTexCoord2f(1, 0); glVertex3f(3, 3, 3);
            glTexCoord2f(1, 1); glVertex3f(3, 3, -3);
            
            glTexCoord2f(1, 1); glVertex3f(3, 3, -3);
            glTexCoord2f(0, 1); glVertex3f(-3, 3, -3);
            glTexCoord2f(0, 0); glVertex3f(-3, 3, 3);
            glEnd();
            
            //cube botton
            glBegin(GL_TRIANGLES);
            glTexCoord2f(0, 0); glVertex3f(-3, -3, 3);
            glTexCoord2f(1, 0); glVertex3f(3, -3, 3);
            glTexCoord2f(1, 1); glVertex3f(3, -3, -3);
            
            glTexCoord2f(1, 1); glVertex3f(3, -3, -3);
            glTexCoord2f(1, 0); glVertex3f(-3, -3, -3);
            glTexCoord2f(0, 0); glVertex3f(-3, -3, 3);
            glEnd();
            break;
    }
    glPopMatrix();
}

void drawFloor()
{
    glColor3f(.5, .5, .5);
    glBegin(GL_POLYGON);
    glVertex3f(-100, -3, -100);
    glVertex3f(-28, -3, -100);
    glVertex3f(-28, -3, -40);
    glVertex3f(-100, -3, -40);
    glEnd();
}

// Routine to draw a bitmap character string.
void writeBitmapString(void *font, char *string)
{
    char *c;
    
    for (c = string; *c != '\0'; c++) glutBitmapCharacter(font, *c);
}

// Routine to convert floating point to char string.
void floatToString(char * destStr, int precision, float val)
{
    sprintf(destStr, "%f", val);
    destStr[precision] = '\0';
}

// Drawing routine.
void drawScene(void)
{
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    n = 0;
    
    // calculate heading
    gluLookAt(my_x, my_y, my_z,
              my_x - sin((M_PI / 180.0)*my_angle), 0, my_z - cos((M_PI / 180.0)*my_angle), 0, 1, 0);
    
    /*lightPos[0] = cos(my_angle);
     lightPos[2] = sin(my_angle);
     
     spotDirection[0] = -lightPos[0];
     spotDirection[2] = -lightPos[2];
     
     glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
     glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spotDirection);*/
    
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, spotAngle);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spotDirection);
    glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, spotExponent);
    
    drawFloor();
    int m=0, j = 0;
    for (n = 0; n <= 132; n++){
        
        if ('1' == output[n]){
            glColor3f(1, 0, 0);
            drawObject(objects[n]);
            cubeLoc[j] = objs[m];
            cubeLoc[j+1] = objs[m+1];
            j+=2;
            m+=2;
        }
        
        if ('2' == output[n]){
            glColor3f(0, 0, 1);
            drawObject(objects[n]);
            cubeLoc[j] = objs[m];
            cubeLoc[j + 1] = objs[m + 1];
            j+=2;
            m+=2;
        }
        
        if ('e' == output[n]){ m += 2; } //do nothing
        
        if ('b' == output[n]){ m += 2; } //do nothing
        
        if ('s' == output[n]){ m += 2; } //do nothing
    }
    
    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    floatToString(theStringBuffer, 4, glutGet(GLUT_ELAPSED_TIME) / 1000);
    glWindowPos3f(1100.0, 10.0, -2.0);
    writeBitmapString((void*)font, "Time: ");
    writeBitmapString((void*)font, theStringBuffer);
    glutPostRedisplay();
    glPopMatrix();
    
    glutSwapBuffers();
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

// Initialization routine.
void setup(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glPolygonOffset(1, 1);
    
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    
    glEnable(GL_COLOR_MATERIAL);
    
    glColorMaterial(GL_FRONT_LEFT, GL_AMBIENT);
    glColorMaterial(GL_FRONT_LEFT, GL_DIFFUSE);
    glColorMaterial(GL_FRONT_LEFT, GL_SPECULAR);
    
    //changing these numbers change color
    float lightAmb[] = { 0.2, 0.2, 0.2, 1.0 };
    float lightDif[] = { 0.6, 0.6, 0.6, 1.0 };
    float lightSpec[] = { .5, .5, .5, 1.0 };
    
    float globAmb[] = { .5, .5, .5, 1.0 };
    
    // Light0 properties.
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDif);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpec);
    
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globAmb); // Global ambient light.
    
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE); // Enable local viewpoint
    glEnable(GL_LIGHT0);
    
    float matSpec[] = { 0.5, 0.5, 0.0, 1.0 };
    float matAmb[] = { 1.0, 1.0, 1.0, 1.0 };
    float matDiff[] = { 0.5, 0.5, 0.5, 1.0 };
    float matShine[] = { 50.0 };
    
    glMaterialfv(GL_FRONT, GL_SPECULAR, matSpec);
    glMaterialfv(GL_FRONT, GL_SHININESS, matShine);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiff);
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
    window_width = w;
    window_height = h;
    
    // initialize to center of window, so that things don't go crazy
    last_mouse_x = w / 2;
    last_mouse_y = h / 2;
    
    float aspect = w*1.0 / h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50, aspect, 0.1, 250);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void gameOver(void)
{
    cout << "You made it!!!  " << endl;
    endTime = glutGet(GLUT_ELAPSED_TIME);
    printScore();
    exit(0);
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
    
    switch (key)
    {
        case 27:                  // escape
            printScore();
            exit(0);
            break;
        case 104:
            
            my_y += 50 * cos((M_PI / 180.0));
            break;
        case 103:
            if (my_y != 0){
                
                my_y = 0;
            }
            break;
        default:
            break;
    }
}

void specialKeyInput(int key, int x, int y)
{
    float tempmy_x = my_x, tempmy_z = my_z, tempmy_angle = my_angle;
    if (my_y == 0)
    {
        switch (key)
        {
            case GLUT_KEY_LEFT:
                tempmy_angle = my_angle + 45;
                
                break;
            case GLUT_KEY_RIGHT:
                tempmy_angle = my_angle - 45;
                
                break;
            case GLUT_KEY_UP:
                tempmy_x = my_x - 3* sin((M_PI / 180.0)*my_angle);
                tempmy_z = my_z -3* cos((M_PI / 180.0)*my_angle);
                break;
            case GLUT_KEY_DOWN:
                tempmy_x = my_x + 3*sin((M_PI / 180.0)*my_angle);
                tempmy_z = my_z + 3*cos((M_PI / 180.0)*my_angle);
                break;
                
        }
        
    }
    
    if (tempmy_angle > 360.0) tempmy_angle -= 360;
    if (tempmy_angle < 0) tempmy_angle += 360;
    
    
    
    if (!objectCollision(tempmy_x, tempmy_z, tempmy_angle))
    {
        isCollision = 0;
        my_x = tempmy_x;
        my_z = tempmy_z;
        my_angle = tempmy_angle;
    }
    else isCollision = 1;
    if ((tempmy_x < -60 && tempmy_x > -74) && (tempmy_z < -95))
    {
        gameOver();
    }
    glutPostRedisplay();
}

void trackMouse(int x, int y)
{
    last_mouse_x = x;
    last_mouse_y = y;
}

// register this with glutIdleFunc
void mousePositionIdleUpdate()
{
    // if the last recorded mouse position is near the horizontal window
    // boundaries, update the angle and redraw the scene
    if (last_mouse_x <= .3*window_width)
    {
        my_angle += 0.07;
        glutPostRedisplay();
    }
    
    else if (last_mouse_x >= .7*window_width)
    {
        my_angle -= 0.07;
        glutPostRedisplay();
    }
    
    if (last_mouse_y <= .2*window_height && up_down_angle >= -1)
    {
        up_down_angle -= 0.008;
        glutPostRedisplay();
    }
    
    else if (last_mouse_y >= .8*window_height && up_down_angle <= 1)
    {
        up_down_angle += 0.008;
        glutPostRedisplay();
    }
    
    if (my_angle > 360.0) my_angle -= 360;
    if (my_angle < 0) my_angle += 360;
}


// Main routine.
int main(int argc, char **argv)
{
    ifstream myReadFile;
    myReadFile.open("/Users/Sami/Downloads/walltest2.txt");
    if (myReadFile.is_open()){
        while (!myReadFile.eof()){
            myReadFile >> output;
        }
    }
    
    //glutInitContextVersion(3, 1);
    //glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
    
    glutInit(&argc, argv);
    startTime = glutGet(GLUT_ELAPSED_TIME);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
    glutInitWindowSize(1200, 625);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Maze Project.cpp");
    glutDisplayFunc(drawScene);
    glutReshapeFunc(resize);
    glutKeyboardFunc(keyInput);
    glutSpecialFunc(specialKeyInput);
    glutPassiveMotionFunc(trackMouse);
    //glutIdleFunc(mousePositionIdleUpdate);
    
    //glewExperimental = GL_TRUE;
    //glewInit();
    
    
    cout << "Use the arrow keys to move around, and hit 'h' to hover over the maze, and hit 'g' to get back on the ground" << endl;
    setup();
    Timer(0);
    
    glutMainLoop();
}
