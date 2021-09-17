#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <math.h>
#include <stdlib.h>

#define LEFT   -1.5
#define RIGHT   1.5
#define TOP     2.5
#define BOTTOM -2.5

//#define LEFT   -5.0
//#define RIGHT   5.0
//#define TOP     5.0
//#define BOTTOM -5.0

const int windowHeight = 800; //window height
const int windowWidth = 800; 	//window width

void myInit(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);       // set black background color
	glColor3f(1.0, 1.0, 1.0);          // set white drawing color
	glPointSize(10.0);		       // a ?dot? is 4 by 4 pixels
	glLineWidth(4.0);		       // a ?dot? is 4 by 4 pixels
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(LEFT, RIGHT, BOTTOM, TOP, -3.5, 3.5);	//box with edges of length 3, 5, and 7
	glMatrixMode(GL_MODELVIEW);
}


void paintShape(char shape)
{
	float radius = 1.5;
	
	glClear(GL_COLOR_BUFFER_BIT);     //clear the screen
	glPushMatrix();                   //save model-view matrix setting
	
	switch(shape)
	{
		case 'c':	//circle
			float theta;
			glBegin(GL_POLYGON);
			glColor3f ( 3.0,  1.0, 0.5); // Yellow
			for (int i = 0; i<360; i++) {
				if (i % 9 == 0) {	//this ensures a 40 sided polygon, as 360/9 = 40
					theta = i*3.142/180;
					glVertex3f(radius*cos(theta), radius*sin(theta), 0);
				}
			}
			glEnd();
			break;
			
		case 'h':	//hexagon
			glBegin(GL_POLYGON);
				glColor3f ( 3.0,  1.0, 0.5); // Yellow
				glVertex3f( 0.0,  1.5, radius);
				glVertex3f(-1.5,  0.75, radius);
				glVertex3f(-1.5, -0.75, radius);
				glVertex3f( 0.0, -1.5, radius);
				glVertex3f( 1.5, -0.75, radius);
				glVertex3f( 1.5,  0.75, radius);
			glEnd();
			break;
			
		case 'l':	//line
			glBegin(GL_LINES);
				glColor3f ( 1.0, 1.8, 4.0);
				glVertex2f(-1.0, 0);
				glVertex2f( 1.0, 0);
			glEnd();
			break;
			
		case 'p':	//point
			glBegin(GL_POINTS);
				glColor3f ( 2.0, 0.5, 0.0);
				glVertex3f(-0.0, 0.0, 0.0);
			glEnd();
			break;
			
		case 's':	//square
			glBegin(GL_QUADS);
				glColor3f (1.0, 0.0, 0.0);
				glVertex3f(-1.0, 1.0, radius);
				glVertex3f( 1.0, 1.0, radius);
				glVertex3f( 1.0,-1.0, radius);
				glVertex3f(-1.0,-1.0, radius);
			glEnd();
			break;
			
		case 't':	//triangle
			glBegin(GL_TRIANGLES);
				glColor3f ( 1.5, 0.0, 1.0);  // Pink
				glVertex3f(-1.0, 1.0, 0.0);
				glVertex3f( 1.0, 1.0, 0.0);
				glVertex3f( 0.0,-1.0, 0.0);
			glEnd();
			break;
			
		case 'u':	//cube
			glRotatef(45, 0, 1, 1);
			glBegin(GL_QUADS);
			
				glColor3f(0.0f,0.0f,1.0f); // Blue
				glVertex3f(-1.0f, 1.0f, 1.0f);
				glVertex3f(-1.0f, 1.0f,-1.0f);
				glVertex3f(-1.0f,-1.0f,-1.0f);
				glVertex3f(-1.0f,-1.0f, 1.0f);
	
				glColor3f(  0.0f, 1.0f, 0.0f); // Green
				glVertex3f( 1.0f, 1.0f,-1.0f);
				glVertex3f(-1.0f, 1.0f,-1.0f);
				glVertex3f(-1.0f, 1.0f, 1.0f);
				glVertex3f( 1.0f, 1.0f, 1.0f);
				
				glColor3f(1.0f,0.5f,0.0f); //Orange
				glVertex3f( 1.0f,-1.0f, 1.0f);
				glVertex3f(-1.0f,-1.0f, 1.0f);
				glVertex3f(-1.0f,-1.0f,-1.0f);
				glVertex3f( 1.0f,-1.0f,-1.0f);
	
				glColor3f(1.0f,0.0f,0.0f); // Red
				glVertex3f( 1.0f, 1.0f, 1.0f);
				glVertex3f(-1.0f, 1.0f, 1.0f);
				glVertex3f(-1.0f,-1.0f, 1.0f);
				glVertex3f( 1.0f,-1.0f, 1.0f);
	
				glColor3f (1.0f,1.0f,0.0f); // Yellow
				glVertex3f( 1.0f,-1.0f,-1.0f);
				glVertex3f(-1.0f,-1.0f,-1.0f);
				glVertex3f(-1.0f, 1.0f,-1.0f);
				glVertex3f( 1.0f, 1.0f,-1.0f);

				glColor3f(1.0f,0.0f,1.0f); //Violet
				glVertex3f( 1.0f, 1.0f,-1.0f);
				glVertex3f( 1.0f, 1.0f, 1.0f);
				glVertex3f( 1.0f,-1.0f, 1.0f);
				glVertex3f( 1.0f,-1.0f,-1.0f);
			glEnd();
			break;
			
		default:
			break; 	//do nothing
	}
	
	glPopMatrix();       // Restore the model-view matrix
	glFlush();          	// send all output to display
}


void myKeyboard(unsigned char theKey, int mouseX, int mouseY)
{
	switch(theKey)
	{
		case 'c':
			paintShape('c');
			break;
		case 'h':
			paintShape('h');
			break;
		case 'l':
			paintShape('l');
			break;
		case 'p':
			paintShape('p');
			break;
		case 's':
			paintShape('s');
			break;
		case 't':
			paintShape('t');
			break;
		case 'u':
			paintShape('u');
			break;
		case 'Q':
		case 'q':
			exit(-1); //terminate the program
		default:
			break; // do nothing
	}
}


void myDisplay(void)
{
	paintShape('t');	//load the triangle shape
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);          						// initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 	// set display mode
	glutInitWindowSize(windowHeight, windowWidth);  // set window size
	glutInitWindowPosition(100, 150); // set window position on screen
	glutCreateWindow("Good Ol Shapes - Type Q or q to quit") ; // open the screen window
	glutDisplayFunc(myDisplay);     						// register redraw function
	glutKeyboardFunc(myKeyboard); 						// register the keyboard action function
	myInit();
	glutMainLoop(); 		     // go into a perpetual loop
}

