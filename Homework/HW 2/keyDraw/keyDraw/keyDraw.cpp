/*	Code written by Jeremy Horky
	Created on: 9/15/2019
	Last modified on: 9/15/2019
	Written for COEN 4830 Fall 2019

	Resources:
*/

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <windows.h>
#include <GL/GL.h>
#include <GL/glut.h>
#include <math.h>

using namespace std;

const int screenWidth = 640;
const int screenHeight = 480;

int lastx = 0;	//lastx and lasty hold previous x and y coords
int lasty = 0;

void myInit(void) {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);
	glViewport(400, 400, 800, 800);
}

void drawDot(int x, int y) {	//draws dot at current x and y, then records previous x and y
	glBegin(GL_POINTS);
	glVertex2i(x, screenHeight - y);
	glEnd();
	glFlush();
	lastx = x;
	lasty = y;
}

void drawLine(int x, int y) {	//draws line between current and previous x and y
	glBegin(GL_LINE_STRIP);
	glVertex2i(lastx, screenHeight - lasty);
	glVertex2i(x, screenHeight - y);
	glEnd();
	glFlush();
	lastx = x;
	lasty = y;
}

void clearFunc(void) {			//clears screen
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINT);
	glEnd();
	glFlush();
	lastx = 0;
	lasty = 0;
}

void myDisplay(void) {

}

void myKeyboard(unsigned char key, int x, int y) {	//waits for a key press
	switch (key) {
	case 'l': drawLine(x, y); break;
	case 'd': drawDot(x, y); break;
	case 'c': clearFunc(); break;
	}
	glFlush();
	glutPostRedisplay();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Go ahead and draw whatever you want!");
	glutKeyboardFunc(myKeyboard);
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();

	return 0;
}

