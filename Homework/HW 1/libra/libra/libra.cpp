/*	Code written by Jeremy Horky
	Created on: 9/6/2019
	Last modified on: 9/6/2019
	Written for COEN 4830 Fall 2019

	Resources:
		Color values: https://web.archive.org/web/20180301041827/https://prideout.net/archive/colors.php
		Libra: https://www.vectorstock.com/royalty-free-vector/night-sky-with-libra-constellation-vector-11699098
*/
#include <windows.h>
#include <GL/GL.h>
#include <GL/glut.h>
#include <math.h>

const int screenWidth = 640;	//set constant screen width and height
const int screenHeight = 480;

void myInit(void) {	//Function sets initial values for colors, point size, and projection. Source for colors in initial comment
	glClearColor(0.098, 0.098, 0.439, 0.0);		
	glColor3f(1.0f, 1.0f, 0.0f);				
	glPointSize(10.0);							
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);
}

void drawLibra(void) {	//Function draws the constellation Libra, based on image source in initial comment
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	glVertex2i(360, 400);
	glVertex2i(500, 300);
	glVertex2i(430, 150);
	glVertex2i(200, 250);
	glVertex2i(175, 300);
	glVertex2i(250, 275);
	glVertex2i(300, 300);
	glVertex2i(300, 125);
	glVertex2i(300, 75);
	glEnd();
	glFlush();
}

int main(int argc, char** argv) {	//main function, adapted from example in lecture
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(screenWidth, screenHeight);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Libra");
	glutDisplayFunc(drawLibra);
	myInit();
	glutMainLoop();

	return 0;
}

