// MechanicProject.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include"ModelSimulator.h"
#include"RigidBody.h"
#include"Point.h"
#include"Scene.h"
#include "Physical.h"
#include<iostream>
#include <glut.h>
#include <memory>

double time = 10;
double Width = 640, Height = 480;
ModelSimulator* ptr_MS;

void Initialize()
{
	glClearColor(255, 255, 255, 1.0);
	glLineWidth(2);
	//Режим матрицы проекций
	glMatrixMode(GL_PROJECTION);
	//Единичная матрица
	glLoadIdentity();
	//Установка двумерной ортографической системы координат 
	gluOrtho2D(-60., 60., -60., 60.);
	//Режим видовой матрицы
	glMatrixMode(GL_MODELVIEW);	
}

//Функция визуализации
void Draw(void)
{
	ptr_MS->render();
}

//Функция анимации
void Timer(int)
{	
	ptr_MS->update();
	glutPostRedisplay();
	glutTimerFunc(time, Timer, 0);
}

//Функция иницивализации начальных данных
void Initialize_data(Point* points, double** edges, int n)
{
	for (int i = 0; i < n; i++)
	{
		edges[i] = new double[n];
	}
	puts("EDGES");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			/*if (i < j)
			std::cin >> edges[i][j];
			else
			edges[i][j]=0;*/
			edges[i][j] = 0;
		}
	}
	edges[0][1] = 1, edges[1][2] = 0.1, edges[1][3] = 0.1;
	puts("Coords");
	/*for (int i = 0; i < n; i++)
	{
	std::cin >> points[i].x;
	std::cin >> points[i].y;
	}*/
	points[0].x = 0, points[0].y = 5, points[1].x = 10, points[1].y = 15;
	points[2].x = -5, points[2].y = 25, points[3].x = 15, points[3].y = 25;
}

//Очитска памяти
void Delete_data(Point* points, double **edges, int n)
{
	delete[] points;
	for (int i = 0; i < n; i++)
	{
		delete[]edges[i];
	}
	delete[]edges;
}

//Здесь объявляются начальные данные и окно opengl
int main(int argc, char ** argv)
{	
	int n = 4;
	Point *points = new Point[n];
	double **edges = new double*[n];
	Initialize_data(points, edges, n);
	Scene SC(4);
	RigidBody RB(points, edges, n);	
	Physical PH(RB);
	std::auto_ptr<ModelSimulator> MS(new ModelSimulator(RB, SC));
	ptr_MS = MS.get();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%lf ", edges[i][j]);
		}
		printf("\n");
	}	
	PH.print();

	glutInit(&argc, argv);

	glutInitWindowSize(Width, Height);
	glutInitWindowPosition(100, 100);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);

	glutCreateWindow("Whirlpool");
	
	glutDisplayFunc(Draw);	
	glutTimerFunc(time, Timer, 0);
	Initialize();
	
	glutMainLoop();
	Delete_data(points, edges, n);
	return 0;
}
