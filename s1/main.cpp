#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <stdlib.h>


const int windowHeight = 800; //window height
const int windowWidth = 800; 	//window width

void myInit(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);       // set black background color
	glColor3f(1.0, 1.0, 1.0);          // set white drawing color
	glPointSize(4.0);		       // a ?dot? is 4 by 4 pixels
	glLineWidth(4.0);		       // a ?dot? is 4 by 4 pixels
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
//	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
//	glOrtho(0, 3.0, 0, 5.0, 0, 7.0);	//box with edges of length 3, 5, and 7
	glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 5.0);	//box with edges of length 3, 5, and 7
	glMatrixMode(GL_MODELVIEW);
}


void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);     // clear the screen
	
	// Dotted line
	glPushMatrix();       // Save model-view matrix setting
	glBegin(GL_POINTS);
		 glColor3f ( 2.0, 0.5, 0.0);
		 glVertex3f(-4.0, 4.0, 0.0);
		 glVertex3f(-3.0, 4.0, 0.0);
		 glVertex3f(-2.0, 4.0, 0.0);
		 glVertex3f(-1.0, 4.0, 0.0);
		 glVertex3f(-0.0, 4.0, 0.0);
		 glVertex3f( 1.0, 4.0, 0.0);
		 glVertex3f( 2.0, 4.0, 0.0);
		 glVertex3f( 3.0, 4.0, 0.0);
		 glVertex3f( 4.0, 4.0, 0.0);
	glEnd();
	glPopMatrix();			// Restore the model-view matrix

	glFlush();          	// send all output to display
}


void myKeyboard(unsigned char theKey, int mouseX, int mouseY)
{
	switch(theKey)
	{
		case 'c':
			break;
		case 'h':
			break;
		case 'l':
			break;
		case 'p':
			break;
		case 's':
			break;
		case 't':
			break;
		case 'u':
			break;
		case 'Q':
		case 'q':
			exit(-1); //terminate the program
		default:
		break; // do nothing
	}
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);          						// initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 	// set display mode
	glutInitWindowSize(windowHeight, windowWidth);  // set window size
	glutInitWindowPosition(100, 150); // set window position on screen
	glutCreateWindow("Big Deep - Type Q or q to quit") ; // open the screen window
	glutDisplayFunc(myDisplay);     						// register redraw function
	glutKeyboardFunc(myKeyboard); 						// register the keyboard action function
	myInit();
	glutMainLoop(); 		     // go into a perpetual loop
}
