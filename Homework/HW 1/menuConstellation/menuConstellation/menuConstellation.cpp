/*	Code written by Jeremy Horky
	Created on: 9/8/2019
	Last modified on: 9/8/2019
	Written for COEN 4830 Fall 2019

	Resources:
		Color values: https://web.archive.org/web/20180301041827/https://prideout.net/archive/colors.php
		Big dipper: https://www.vectorstock.com/royalty-free-vector/big-dipper-or-ursa-major-great-bear-constellation-vector-16896708
		Libra: https://www.vectorstock.com/royalty-free-vector/night-sky-with-libra-constellation-vector-11699098
		Cassiopeia: https://www.vectorstock.com/royalty-free-vector/cassiopeia-constellation-vector-6820601
		Aquila: https://www.vectorstock.com/royalty-free-vector/aquila-constellation-with-beautiful-bright-stars-vector-9177440
*/

#include <windows.h>
#include <GL/GL.h>
#include <GL/glut.h>
#include <math.h>

#define DIPPER 1
#define LIBRA 2
#define CASS 3
#define AQUILA 4

const int screenWidth = 640;	//set constant screen width and height
const int screenHeight = 480;
GLfloat pointSize = 10.0;		//universal size for all GL points

void myInit(void) {	//Function sets initial values for colors, point size, and projection. Source for colors in initial comment
	glClearColor(0.098, 0.098, 0.439, 0.0);
	glColor3f(1.0f, 1.0f, 0.0f);
	glPointSize(pointSize);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)screenWidth, 0.0, (GLdouble)screenHeight);
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

void drawCass(void) {	//Function draws the constellation Cassiopeia, based on image source in initial comment
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	glVertex2i(170, 340);
	glVertex2i(245, 240);
	glVertex2i(320, 240);
	glVertex2i(395, 140);
	glVertex2i(470, 200);
	glEnd();
	glFlush();
}

void drawAquila(void) {	//Function draws the constellation Aquila, based on image source in initial comment
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	glVertex2i(135, 195);
	glVertex2i(195, 210);
	glVertex2i(245, 340);
	glVertex2i(320, 240);
	glVertex2i(395, 380);
	glVertex2i(435, 400);
	glVertex2i(395, 140);
	glVertex2i(435, 120);
	glEnd();
	glFlush();
}

void processMenuEvents(int option) {
	switch (option) {
		case DIPPER: glutDisplayFunc(drawDipper); break;
		case LIBRA: glutDisplayFunc(drawLibra); break;
		case CASS: glutDisplayFunc(drawCass); break;
		case AQUILA: glutDisplayFunc(drawAquila); break;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv) {	//main function, adapted from example in lecture
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(screenWidth, screenHeight);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Constellations");
	glutDisplayFunc(drawDipper);
	myInit();
	glutCreateMenu(processMenuEvents);
	glutAddMenuEntry("Big Dipper", DIPPER);
	glutAddMenuEntry("Libra", LIBRA);
	glutAddMenuEntry("Cassiopeia", CASS);
	glutAddMenuEntry("Aquila", AQUILA);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}
