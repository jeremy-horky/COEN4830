/*	Code written by Jeremy Horky
	Created on: 9/11/2019
	Last modified on: 9/11/2019
	Written for COEN 4830 Fall 2019

	Resources:
		Tiling: https://community.khronos.org/t/drawing-an-object-multiple-times-using-viewports/68647
		Creating a random number generator: https://stackoverflow.com/questions/7560114/random-number-c-in-some-range
		Colors: http://doc.instantreality.org/tools/color_calculator/
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

void setColor(int r) {
	switch (r) {
	case 0: glColor3f(0.678f, 0.0f, 0.007f); break;
	case 1: glColor3f(0.129f, 0.243f, 0.117f); break;
	case 2: glColor3f(0.321f, 0.019f, 1.0f); break;
	case 3: glColor3f(0.670f, 0.670f, 0.670f); break;
	case 4: glColor3f(1.0f, 0.0f, 0.0f); break;
	case 5: glColor3f(1.0f, 0.517f, 0.019f); break;
	case 6: glColor3f(0.482f, 0.0f, 0.658f); break;
	default: glColor3f(0.807f, 0.686f, 0.352f); break;
	}
}

void drawHouse(int houseColor, int roofColor){
	int c1 = 75;
	int c2 = 275;
	int c3 = 325;

	int x1 = 25;
	int y1 = 275;
	int x2 = 375;
	int y2 = 275;
	int x3 = 200;
	int y3 = 400;

	int d1 = 75;
	int d2 = 225;
	int d3 = 175;
	int d4 = 225;

	int w1 = 125;
	int w2 = 225;
	int w3 = 100;
	int w4 = 150;
	int w5 = 250;
	int w6 = 300;

	setColor(houseColor);
	glBegin(GL_POLYGON);
	glVertex2i(c1, c1);
	glVertex2i(c1, c2);
	glVertex2i(c3, c2);
	glVertex2i(c3, c1);
	glEnd();
	glFlush();

	setColor(roofColor);
	glBegin(GL_TRIANGLES);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glVertex2i(x3, y3);
	glEnd();
	glFlush();

	glColor3f(0.709f, 0.415f, 0.109f);
	glBegin(GL_POLYGON);
	glVertex2i(d3, d1);
	glVertex2i(d3, d2);
	glVertex2i(d4, d2);
	glVertex2i(d4, d1);
	glEnd();
	glFlush();

	glColor3f(0.490f, 0.831f, 0.768f);
	glBegin(GL_POLYGON);
	glVertex2i(w3, w1);
	glVertex2i(w3, w2);
	glVertex2i(w4, w2);
	glVertex2i(w4, w1);
	glEnd();
	glFlush();
	glBegin(GL_POLYGON);
	glVertex2i(w5, w1);
	glVertex2i(w5, w2);
	glVertex2i(w6, w2);
	glVertex2i(w6, w1);
	glEnd();
	glFlush();
}

void drawVillage(void){
	glClear(GL_COLOR_BUFFER_BIT);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			int rand1 = (std::rand() % (7 + 1));
			int rand2 = (std::rand() % (7 + 1));
			glViewport(i * 64, j * 48, 64, 48);
			drawHouse(rand1, rand2);
		}
	}
	glEnd();
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Garishville");
	glutDisplayFunc(drawVillage);
	myInit();
	glutMainLoop();

	return 0;
}

