/*	Code written by Jeremy Horky
	Created on: 9/6/2019
	Last modified on: 9/6/2019
	Written for COEN 4830 Fall 2019

	Resources:
		Color values: https://web.archive.org/web/20180301041827/https://prideout.net/archive/colors.php
		Big dipper: https://www.vectorstock.com/royalty-free-vector/big-dipper-or-ursa-major-great-bear-constellation-vector-16896708
*/
#include <windows.h>
#include <GL/GL.h>
#include <GL/glut.h>
#include <math.h>

const int screenWidth = 640;	//set constant screen width and height
const int screenHeight = 480;
GLfloat pointSize = 5.0;		//universal size for all GL points

void myInit(void) {	//Function sets initial values for colors, point size, and projection. Source for colors in initial comment
	glClearColor(0.098, 0.098, 0.439, 0.0);
	glColor3f(1.0f, 1.0f, 0.0f);
	glPointSize(pointSize);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);
}

void myMouse(int button, int state, int x, int y) {	//function changes point size based on mouse click
	if (state == GLUT_DOWN) {	
		if (button == GLUT_LEFT_BUTTON) {	//if left button is clicked
			pointSize = pointSize + 1.0;	//increase pointSize by 1
			if (pointSize > 20.0) pointSize = 1.0;	//edge case to avoid points getting too big
			glPointSize(pointSize);			//update point size
			glFlush();
			glutPostRedisplay();
		}
		else if (button == GLUT_RIGHT_BUTTON) {	//if right button is clicked
			pointSize = pointSize - 1.0;		//decrease pointSize by 1
			if (pointSize < 1.0) pointSize = 20.0;	//edge case to avoid points getting too small
			glPointSize(pointSize);			//update point size
			glFlush();
			glutPostRedisplay();
		}
	}
}

void myKeyboard(unsigned char key, int x, int y) {	//function to change point color based on key presses
	switch (key) {
	case 'y':										//set color to yellow
		glColor3f(1.0f, 1.0f, 0.0f);
		break;
	case 'g':										//set color to green
		glColor3f(0.0f, 1.0f, 0.0f);
		break;
	case 'b':										//set color to blue
		glColor3f(0.0f, 0.0f, 1.0f);
		break;
	case 'r':										//set color to red
		glColor3f(1.0f, 0.0f, 0.0f);
		break;
	case 'w':										//set color to white
		glColor3f(1.0f, 1.0f, 1.0f);
		break;
	case 'k':										//set color to black (key)
		glColor3f(0.0f, 0.0f, 0.0f);
		break;
	case 'a':										//set color to aqua
		glColor3f(0.0f, 1.0f, 1.0f);
		break;
	case 'p':										//set color to purple
		glColor3f(1.0f, 0.0f, 1.0f);
		break;
	}
	glFlush();										//update point color
	glutPostRedisplay();
}

void drawDipper(void) {	//Function draws the Big Dipper, based on image source in initial comment
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	glVertex2i(150, 310);
	glVertex2i(210, 350);
	glVertex2i(280, 295);
	glVertex2i(340, 240);
	glVertex2i(380, 150);
	glVertex2i(455, 125);
	glVertex2i(530, 200);
	glEnd();
	glFlush();
}

int main(int argc, char** argv) {	//main function, adapted from example in lecture
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(screenWidth, screenHeight);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Big Dipper");
	glutMouseFunc(myMouse);
	glutKeyboardFunc(myKeyboard);
	glutDisplayFunc(drawDipper);
	myInit();
	glutMainLoop();
	return 0;
}

