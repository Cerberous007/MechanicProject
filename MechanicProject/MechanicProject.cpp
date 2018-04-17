// MechanicProject.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <glut.h>
void Display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}
void Initialize() {
	glClearColor(255, 255, 255, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-200.0, 200.0, -200.0, 200.0, -5.0, 5.0);
}
int main(int argc, char ** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(100, 200);
	glutCreateWindow("Our first GLUT application!");
	glutDisplayFunc(Display);
	Initialize();
	glutMainLoop();
	return 0;
}

