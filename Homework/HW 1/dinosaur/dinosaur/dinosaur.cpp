/*	Code written by Jeremy Horky
	Created on: 9/4/2019
	Last modified on: 9/8/2019
	Written for COEN 4830 Fall 2019

	Resources:
		Code taken from book
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

void myInit(void) {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);

}

void drawPolyLineFile() {
	fstream inStream;
	inStream.open("..\\dino.dat", ios::in);
	if (inStream.fail()) return;
	glClear(GL_COLOR_BUFFER_BIT);
	GLint numpolys, numLines, x, y;
	inStream >> numpolys;
	for (int j = 0; j < numpolys; j++) {
		inStream >> numLines;
		glBegin(GL_LINE_STRIP);
		for (int i = 0; i < numLines; i++) {
			inStream >> x >> y;
			glVertex2i(x, y);
		}
		glEnd();
	}
	glFlush();
	inStream.close();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Dino Boi");
	glutDisplayFunc(drawPolyLineFile);
	myInit();
	glutMainLoop();

	return 0;
}

