/*	Code written by Jeremy Horky
	Created on: 9/12/2019
	Last modified on: 9/12/2019
	Written for COEN 4830 Fall 2019

	Resources:
		Code adapted from part 3 of this assignment
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

int xpos = 288;
int ypos = 216;

float colors[10][10][2][3];
int scale[10][10][2];

int destroyed[10][10];	//records if dinosaur has crushed any houses, 0 for no 1 for yes

void myInit(void) {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);
}

void setColor(int r, int i, int j, int flag) {
	switch (r) {
	case 0:
		colors[i][j][flag][0] = 0.678;
		colors[i][j][flag][1] = 0.0;
		colors[i][j][flag][2] = 0.007;
		break;
	case 1:
		colors[i][j][flag][0] = 0.129;
		colors[i][j][flag][1] = 0.243;
		colors[i][j][flag][2] = 0.117;
		break;
	case 2:
		colors[i][j][flag][0] = 0.321;
		colors[i][j][flag][1] = 0.019;
		colors[i][j][flag][2] = 1.0;
		break;
	case 3:
		colors[i][j][flag][0] = 0.670;
		colors[i][j][flag][1] = 0.670;
		colors[i][j][flag][2] = 0.670;
		break;
	case 4:
		colors[i][j][flag][0] = 1.0;
		colors[i][j][flag][1] = 0.0;
		colors[i][j][flag][2] = 0.0;
		break;
	case 5:
		colors[i][j][flag][0] = 1.0;
		colors[i][j][flag][1] = 0.517;
		colors[i][j][flag][2] = 0.019;
		break;
	case 6:
		colors[i][j][flag][0] = 0.482;
		colors[i][j][flag][1] = 0.0;
		colors[i][j][flag][2] = 0.658;
		break;
	default:
		colors[i][j][flag][0] = 0.807;
		colors[i][j][flag][1] = 0.686;
		colors[i][j][flag][2] = 0.352;
		break;
	}
}

void drawHouse(int i, int j) {
	int c1 = 132 + 75;
	int c2 = 275;
	int c3 = 132 + 375;
	int c4 = 75;

	int x1 = 132 + 25;
	int y1 = 275;
	int x2 = 132 + 425;
	int y2 = 275;
	int x3 = 132 + 225;
	int y3 = 400;

	int d1 = 75;
	int d2 = 225;
	int d3 = 132 + 200;
	int d4 = 132 + 250;

	int w1 = 150;
	int w2 = 225;
	int w3 = 132 + 125;
	int w4 = 132 + 175;
	int w5 = 132 + 275;
	int w6 = 132 + 325;

	glColor3f(colors[i][j][0][0], colors[i][j][0][1], colors[i][j][0][2]);
	glBegin(GL_POLYGON);
	glVertex2i(c1, c4);
	glVertex2i(c1, c2);
	glVertex2i(c3, c2);
	glVertex2i(c3, c4);
	glEnd();
	glFlush();

	glColor3f(colors[i][j][1][0], colors[i][j][1][1], colors[i][j][1][2]);
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

void drawRubble(int i, int j) {	//draws a pile of rubble if the house has been destroyed
	int x1 = 25;
	int y1 = 75;
	int x2 = 615;
	int y2 = 75;
	int x3 = 295;
	int y3 = 200;

	int x4 = 132 + 75;
	int y4 = 100;
	int x5 = 132 + 325;
	int y5 = 75;
	int x6 = 132 + 225;
	int y6 = 150;
	int x7 = 132 + 125;
	int y7 = 125;
	int x8 = 132 + 245;
	int y8 = 125;
	int x9 = 132 + 225;
	int y9 = 150;

	glColor3f(colors[i][j][0][0], colors[i][j][0][1], colors[i][j][0][2]);
	glBegin(GL_TRIANGLES);
	glVertex2i(x1, y1);
	glVertex2i(x2, y2);
	glVertex2i(x3, y3);
	glEnd();
	glFlush();

	glPointSize(4.0);
	glColor3f(colors[i][j][1][0], colors[i][j][1][1], colors[i][j][1][2]);
	glBegin(GL_POINTS);
	glVertex2i(x4, y4);
	glVertex2i(x5, y5);
	glVertex2i(x6, y6);
	glVertex2i(x7, y7);
	glVertex2i(x8, y8);
	glVertex2i(x9, y9);
	glEnd();
	glFlush();
}

void drawPolyLineFile() {
	glColor3f(0.0f, 0.0f, 0.0f);
	fstream inStream;
	inStream.open("..\\dino.dat", ios::in);
	if (inStream.fail()) return;
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
	glutSwapBuffers();
}

void drawDino(void) {
	glViewport(xpos, ypos, 64, 48);
	drawPolyLineFile();
	glFlush();
	glEnd();
	glutSwapBuffers();
}

void redrawVillage(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			glViewport(i * 64, j * 48, scale[i][j][0], scale[i][j][1]);
			if (destroyed[i][j] == 0) {
				drawHouse(i, j);
			}
			else if (destroyed[i][j] == 1) {
				drawRubble(i, j);
			}
		}
	}
	drawDino();
}

void myKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'w': ypos += 1; redrawVillage(); break;
	case 'a': xpos -= 1; redrawVillage(); break;
	case 's': ypos -= 1; redrawVillage(); break;
	case 'd': xpos += 1; redrawVillage(); break;
	}
	bool onHouse = false;	//loops used to check if the dinosaur is (roughly) on top of a house
	int i;
	int j;
	//x:157-483
	//y:75-400
	for (int k = 0; k < 10; k++) {
		for (int l = 0; l < 10; l++) {
			int xmin = 64 * k + 16;
			int xmax = 64 * (k+1) - 16;
			int ymin = 48 * l + 12;
			int ymax = 48 * (l+1) - 12;
			if (((xpos + 32) >= xmin) && ((xpos + 32) <= xmax)) {
				if (((ypos + 24) >= ymin) && ((ypos + 24) <= ymax)) {
					onHouse = true;
					//printf("On house (%d,%d)", k, l);
					i = k;
					j = l;
				}
			}
		}
	}
	if (onHouse) {	//if the dino is on a house, it records which one
		destroyed[i][j] = 1;
		//printf("House (%d,%d) destroyed", i, j);
	}
	glFlush();
	glutSwapBuffers();
}

void drawVillage(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			int rand1 = (std::rand() % (7 + 1));
			int rand2 = (std::rand() % (7 + 1));
			int scale1 = 16 + (std::rand() % (64 - 16 + 1));
			int scale2 = 16 + (std::rand() % (48 - 16 + 1));
			setColor(rand1, i, j, 0);
			setColor(rand2, i, j, 1);
			scale[i][j][0] = scale1;
			scale[i][j][1] = scale2;
			glViewport(i * 64, j * 48, scale1, scale2);
			drawHouse(i, j);
		}
	}
	glutSwapBuffers();
	redrawVillage();
	drawDino();
	glEnd();
	glFlush();
	glutSwapBuffers();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Oh no! The dino is destroying Garishville!");
	glutKeyboardFunc(myKeyboard);
	glutDisplayFunc(drawVillage);
	myInit();
	glutMainLoop();

	return 0;
}