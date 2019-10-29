#include <iostream>
#include <Windows.h>
#include <GL/glut.h>
#include <math.h>

void init() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	gluOrtho2D(-10, 10, -12, 10);
}

void drawRoof(float startX, float startY, float radius, float start, float size) {
	// Roof
	glBegin(GL_LINE_STRIP);
	for (float i = start; i < size + start; i++) {
		float degreesInRadians = i * 3.1415926535 / 180;
		glVertex2f(cos(degreesInRadians) * radius + startX, sin(degreesInRadians) * radius + startY);
	}
	glEnd();
}

void drawMoon() {
	float startX = 7.0, startY = 7.0, radius = 2.0, size = 360;
	glColor3f(0.858824 , 0.858824 , 0.439216);
	glBegin(GL_POLYGON);
	for (float i = 0; i < size; i++) {
		float degreesInRadians = i * 3.1415926535 / 180;
		glVertex2f(cos(degreesInRadians) * radius + startX, sin(degreesInRadians) * radius + startY);
	}
	glEnd();
	startX = 7.0 + 1.0;
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (float i = 0; i < size; i++) {
		float degreesInRadians = i * 3.1415926535 / 180;
		glVertex2f(cos(degreesInRadians) * radius + startX, sin(degreesInRadians) * radius + startY);
	}
	glEnd();
}

void drawWalls() {
	// Walls
	glBegin(GL_LINE_LOOP);
	glVertex2f(-8, 1);
	glVertex2f(8, 1);
	glVertex2f(8, -1);
	glVertex2f(6.5, -1);
	glVertex2f(6.5, -10);
	glVertex2f(-6.5, -10);
	glVertex2f(-6.5, -1);
	glVertex2f(-8, -1);
	glEnd();
}

void drawDoor() {
	// Door
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(1.5, -10);
	glVertex2f(-1.5, -10);
	glVertex2f(-1.5, -5);
	glVertex2f(1.5, -5);
	glEnd();

}

void drawWindows(float point1[2], float point2[2], float point3[2], float point4[2]) {
	glBegin(GL_LINE_LOOP);
	glVertex2f(point1[0], point1[1]);
	glVertex2f(point2[0], point2[1]);
	glVertex2f(point3[0], point3[1]);
	glVertex2f(point4[0], point4[1]);
	glEnd();
}

void drawKnob() {
	float rad;
	// Door Knob
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i <= 360; i++)
	{
		rad = i * 3.142 / 180;
		glVertex2f(1.0 + 0.2 * sin(rad), -7.5 + 0.2 * cos(rad));
	}
	glEnd();
}

void house() {
	float point1[2] = {-4.5, -5}, point2[2] = {-4.5, -7.5}, point3[2] = {-2.0, -7.5}, point4[2] = {-2.0, -5};
	float point5[2] = { 2.0, -5 }, point6[2] = { 2.0, -7.5 }, point7[2] = { 4.5, -7.5 }, point8[2] = { 4.5, -5 };
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(2.0);//sets the width of the line
	drawMoon();
	glColor3f(0.0, 0.0, 1.0);
	drawRoof(0, 1, 4, 0, 180);
	drawWalls();
	drawDoor();
	//Window 1
	drawWindows(point1, point2, point3, point4);
	//Window 2
	drawWindows(point5, point6, point7, point8);

	glColor3f(0.0, 0.0, 1.0);
	// Window panes 1
	glBegin(GL_LINES);
		glVertex2f(-3.25, -5);
		glVertex2f(-3.25, -7.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(-4.5, -6.25);
	glVertex2f(-2, -6.25);
	glEnd();

	// Window panes 2
	glBegin(GL_LINES);
	glVertex2f(3.25, -5);
	glVertex2f(3.25, -7.5);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(4.5, -6.25);
	glVertex2f(2, -6.25);
	glEnd();

	drawKnob();
	
	glFlush();//enables fast execution of statements
}

int main(int argc, char** argv) {
	glutInit(&argc, argv); 
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(500, 500); glutCreateWindow("Simple House");

	init();
	glutDisplayFunc(house);
	glutMainLoop();
}