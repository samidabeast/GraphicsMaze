#  include <GL/glew.h>
#include <GL/freeglut.h>
#  include <GL/glext.h>
#pragma comment(lib, "glew32.lib") 
#endif
# include <iostream>
using namespace std;
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <cstdlib>
#include <fstream>

static int isSelecting = 0;
static unsigned int buffer[1024]; // Hit buffer.


#define PI 3.14159265
enum ObjType { CUBE, TEAPOT, CONE , CYLINDER,SPHERE,TORUS,SPHERELARGE};

static int globalminZ = 99999999;
// set up variables to process mouse
static int window_width;
static int window_height;
static int last_mouse_x;
static int last_mouse_y;

//float lastx, lasty;
static int isCollision = 0;
typedef struct
{
	ObjType type;

	float x;
	float y;
	float z;

	int selected;
} object;


static const int num_objects = 11;

static object objects[] =
{ { CUBE, 0, -.2, -10, 0 },
{ TEAPOT, 0, .9, -10, 0 },
{ CONE, 5, -1, -10, 0 },
{ CONE, -5, -1, -10, 0 },
{CYLINDER, -8, -1, -7, 0},
{ CYLINDER, 8, -1, -7, 0 },
{ CYLINDER, 8, -1, -15, 0 },
{ CYLINDER, -8, -1, -15, 0 },
{ SPHERE, 0, 5, -5, 0 },
{TORUS, 0,2,-20,0},
{SPHERELARGE, 0,5,-10,0 }

};

static float my_x = 0;
static float my_y = 0;
static float my_z = 0;
static float my_angle = 0;


int checkSpheresIntersection(float x1, float y1, float z1, float r1,
	float x2, float y2, float z2, float r2)
{
	
	return ((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) + (z1 - z2)*(z1 - z2) <= (r1 + r2)*(r1 + r2));
}
int objectCollision(float x, float z, float a)
{
//this array holds the x , y, z locations for cube centers. 
	int objs[] = {
		0, -.2, -10, 
		-5, -1, -10,
		5, -1, -10,
		-8, -1, -7,
		8, -1, -7 
	};
	float camx = x;
	float camz = z;
	float camangle = a;
	int i,j;
	//float d;
	int arrCount = sizeof(objs) / sizeof(objs[0]);

	for (i = 0; i < arrCount; i+= 3)
	{
		if (checkSpheresIntersection(camx - 1 * sin((PI / 180.0) * camangle), 0.0,
			camz - 1 * cos((PI / 180.0) * camangle), 1,
			objs[i], objs[i+1],
			objs[i+2], .3))
			return 1;
	
	}
	
	
	return 0;
}
 
void drawFloor()
{
	glColor3f(.5, .5, .5);
	glBegin(GL_POLYGON);
	glVertex3f(-100, -1, -100);
	glVertex3f(100, -1, -100);
	glVertex3f(100, -1, 100);
	glVertex3f(-100, -1, 100);
	glEnd();

}
static int r = 0;
static int turn = 0;
void update(int ignore)
{
	if (r < 365 )
	{
		
		r += 5;
		
	}
	else if (r > 360)
	{
		r = 0;
	}

	glutPostRedisplay();
	glutTimerFunc(50, update, 0);
	
}

void drawObject(const object& o)
{
	glPushMatrix();
	glTranslatef(o.x, o.y, o.z);
	glLineWidth(1);


	if (o.selected)
	{
		glColor3f(1.0, 0.0, 0.0);
		
	}
	else
	{
		glColor3f(0.0, 1.0, 1.0);
		
	}



	switch (o.type)
	{
	case CUBE:

		glutSolidCube(1.8);
		glColor3f(0, 0, 0);

		glutWireCube(1.8);

		break;

	case SPHERELARGE:
		
		glutSolidSphere(20,2,3);
		glColor3f(0, 0, 0);

		glutWireSphere(20,2,3);

		break;

	case TEAPOT:
		
		glRotatef(r, 0, 1, 0);
		glScalef(.30, .30, .30);
		glutSolidTeapot(1);
		glColor3f(1, 0, 1);
		glutWireTeapot(1);
		
		break;


	case CONE:
		
		glRotatef(90, -1, 0, 0);
		glScalef(0.35, 0.35, 0.35);
		glutSolidCone(5, 10, 5, 3);
		glColor3f(0, 0, 0);
		glutWireCone(5, 10, 5, 3);

		
		break;

	case CYLINDER:
		
		glRotatef(90, -1, 0, 0);
		glutSolidCylinder(2, 6, 18, 3);
		
		glColor3f(0, 0, 0);
		glutWireCylinder(2, 6, 18, 3);
		
		break;
	case SPHERE:
		
		glRotatef(90, -1, 0, 0);
		glutSolidSphere(3, 12, 10);
		glColor3f(0, 1, 0);

		glutWireSphere(3,12,10);
		break;

	case TORUS:
		
		glutSolidTorus(1, 2, 20, 15);
		glColor3f(0, 0, 0);
		glutWireTorus(1, 2, 20, 15);
	
		break;
	}


	glPopMatrix();
}
static int highlightFrames = 10;
static unsigned int closestName = 0;
void drawShapes()
{
	

	for (int i = 0; i<num_objects; i++)
	{
		
		if (isSelecting) glLoadName(i) ;
			  
		drawObject(objects[i]);
		
	}
	if (isSelecting)glPopName();
	
}

// Drawing routine.
void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	// calculate heading

	gluLookAt(my_x, my_y, my_z, my_x - sin((PI / 180)*my_angle), 0, my_z -  cos((PI / 180.0)*my_angle), 0, 1, 0);


	drawFloor();
	drawShapes();
	//for (int i = 0; i<num_cs; i++)
	//{
	//	drawObject(objects[i]);
	//}

	glutSwapBuffers();
}

void pickFunction(int button, int state, int x, int y)
{

	int viewport[4]; // Viewport data.

	if (button != GLUT_LEFT_BUTTON || state != GLUT_DOWN) return; // Don't react unless left button is pressed.

	glGetIntegerv(GL_VIEWPORT, viewport); // Get viewport data.

	glSelectBuffer(1024, buffer); // Specify buffer to write hit records in selection mode
	glRenderMode(GL_SELECT); // Enter selection mode.

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();

	// Define a viewing volume corresponding to selecting in 3 x 3 region around the cursor.
	glLoadIdentity();
	gluPickMatrix((float)x, (float)(viewport[3] - y), 3.0, 3.0, viewport);
	// glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0); // Copied from the reshape routine.
	gluPerspective(50, 1, 0.1, 250);
	gluLookAt(my_x, my_y, my_z, my_x - sin((PI / 180)*my_angle), 0, my_z - cos((PI / 180.0)*my_angle), 0, 1, 0);

	glMatrixMode(GL_MODELVIEW); // Return to modelview mode before drawing.
	glLoadIdentity();

	glInitNames(); // Initializes the name stack to empty.
	glPushName(0); // Puts name 0 on top of stack.

	isSelecting = 1;
	drawShapes();
	isSelecting = 0;
	glPopName();

	int hits = glRenderMode(GL_RENDER);

	printf("clicked on %d thing[s]\n", hits);

	if (hits > 0)
	{
		unsigned int* ptr = buffer;
		unsigned int name=1;
		
		for (int i = 0; i<hits; i++)
		{
			ptr++;

			unsigned int minZ = *ptr;
			ptr += 2;
			unsigned int stack_top = *ptr;
			ptr++;
			
			if (minZ < globalminZ || i ==0)
			{
				globalminZ = minZ;

				name = stack_top;
				
			}
			printf("item %u at %f\n", stack_top, minZ*1.0 / 0xffffffff);
		}
		objects[name].selected = !objects[name].selected;
	}
	
	
	// Restore viewing volume of the resize routine and return to modelview mode.
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);

	glutPostRedisplay();
}

// Initialization routine.
void setup(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_POLYGON_OFFSET_FILL);
	glPolygonOffset(1, 1);
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
	//   glFrustum(-5,5,-5,5,5,200);
	//   glOrtho(-5,5,-5,5,0,200);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void trackMouse(int x, int y)
{
	last_mouse_x = x;
	last_mouse_y = y;
	//cout << last_mouse_x;
	
		
}
static int current_mouse ;
static int old_mouse;// = window_width / 2;
//not using this mouse movement. 
void mousePositionIdleUpdate()
{
	//current_mouse = last_mouse_x;
	//// if the last recorded mouse position is near the horizontal window
	//// boundaries, update the angle and redraw the scene
	//
	//if (current_mouse == last_mouse_x)
	//{
	//	old_mouse = current_mouse;
	//}
	//else
	//{
	//	//old_mouse = current_mouse;
	//	current_mouse = last_mouse_x;
	//}
	//
	////current_mouse = last_mouse_x;
	//int mouseDiff = 0;
	//
	//if (old_mouse < last_mouse_x)
	//{
	//	mouseDiff = current_mouse - old_mouse;
	//	my_angle += mouseDiff;
	//	cout << mouseDiff;
	//	current_mouse = last_mouse_x;
	//	glutPostRedisplay();
	//}

	//if (old_mouse > current_mouse)
	//{
	//	mouseDiff = old_mouse - current_mouse;
	//	my_angle -= mouseDiff;
	//	current_mouse = last_mouse_x;
	//	glutPostRedisplay();
	//}
	if (last_mouse_x <= .4*window_width && last_mouse_x > .3*window_width)
	{
		my_angle += 0.2;
		glutPostRedisplay();
	}
	else if (last_mouse_x <= .3*window_width && last_mouse_x > .2*window_width)
	{
		my_angle += 0.4;
		glutPostRedisplay();
	}
	else if (last_mouse_x <= .2*window_width && last_mouse_x > .1*window_width)
	{
		my_angle += 0.6;
		glutPostRedisplay();
	}
	else if (last_mouse_x <= .1*window_width )
	{
		my_angle += 1;
		glutPostRedisplay();
	}
	else if (last_mouse_x >= .6*window_width && last_mouse_x < .7*window_width)
	{
		my_angle -= 0.2;
		glutPostRedisplay();
	}
	else if (last_mouse_x >= .7*window_width && last_mouse_x < .8*window_width)
	{
		my_angle -= 0.4;
		glutPostRedisplay();
	}
	else if (last_mouse_x >= .8*window_width && last_mouse_x < .9*window_width)
	{
		my_angle -= 0.6;
		glutPostRedisplay();
	}
	else if (last_mouse_x >= .9*window_width )
	{
		my_angle -= 1;
		glutPostRedisplay();
	}


}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:                  // escape
		exit(0);
		break;
	case 104:
		//my_angle += 10;
		my_y += 50 * cos((PI / 180.0)*my_angle);
		break;
	case 103:
		if (my_y != 0){
		my_y -= 50 * cos((PI / 180.0)*my_angle);
		}
		break;
	default:
		break;
	}
//	glutPostRedisplay();
}
// this does the moving with the collision detection
void specialKeyInput(int key, int x, int y)
{
	//int coll;
	//if (objectCollision(my_x, my_z, my_y))
	//{
	//	 coll = 1;
	//	cout << "object detected" << endl;
	//}
	//else
	//	coll = 0;

	float tempmy_x = my_x, tempmy_z = my_z, tempmy_angle = my_angle;
	if (my_y == 0)
	{
		switch (key)
		{
		case GLUT_KEY_LEFT:
			tempmy_angle = my_angle + 45;
			//my_x -= (1 * cos((PI / 180.0)*my_angle));
			//my_z += (1 * sin((PI / 180.0)*my_angle));
			break;
		case GLUT_KEY_RIGHT:
			tempmy_angle = my_angle - 45;
			//my_x += (1 * cos((PI / 180.0)*my_angle));
			//my_z -= (1 * sin((PI / 180.0)*my_angle));
			break;
		case GLUT_KEY_UP:
			tempmy_x = my_x - sin((PI / 180.0)*my_angle);
			tempmy_z = my_z - cos((PI / 180.0)*my_angle);
			break;
		case GLUT_KEY_DOWN:
			tempmy_x =  my_x + sin((PI / 180.0)*my_angle);
			tempmy_z = my_z + cos((PI / 180.0)*my_angle);
			break;

		}
		//	glutPostRedisplay();
	}
	//else
	//{
		/*coll = 0;
		my_x += 1 * sin((PI / 180.0)*my_angle);
		my_z += 1 * cos((PI / 180.0)*my_angle);*/
	//}
	if (tempmy_angle > 360.0) tempmy_angle -= 360;
	if (tempmy_angle < 0) tempmy_angle += 360;

	//    printf("my angle: %f\n", my_angle);

	if (!objectCollision(tempmy_x, tempmy_z, tempmy_angle))
	{
		isCollision = 0;
		my_x = tempmy_x;
		my_z = tempmy_z;
		my_angle = tempmy_angle;
	}
	else isCollision = 1;

	glutPostRedisplay();
}



// Main routine.
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
	glutInitWindowSize(1000, 900);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("colored objects");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);
	glutSpecialFunc(specialKeyInput);
	glutPassiveMotionFunc(trackMouse);
	//glutIdleFunc(mousePositionIdleUpdate);
	glutMouseFunc(pickFunction);
	
	glewExperimental = GL_TRUE;
	glewInit();

	setup();
	glutTimerFunc(50, update, 0);
	glutMainLoop();
}
