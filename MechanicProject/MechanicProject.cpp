// MechanicProject.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include"ModelSimulator.h"
#include"RigidBody.h"
#include"Point.h"
#include"Scene.h"
#include<iostream>
#include <glut.h>
#include <memory>

float Width = 640, Height = 480;
ModelSimulator* ptr_MS;

void Initialize()
{
	glClearColor(0, 0, 0, 1.0);
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

void Timer(int)
{
	//Draw();
	ptr_MS->update();
	glutPostRedisplay();
	glutTimerFunc(50, Timer, 0);
}

void Initialize_data(Point* points, float** edges, int n)
{
	for (int i = 0; i < n; i++)
	{
		edges[i] = new float[n];
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
	edges[0][1] = 1, edges[1][2] = 1, edges[1][3] = 1;
	puts("Coords");
	/*for (int i = 0; i < n; i++)
	{
	std::cin >> points[i].x;
	std::cin >> points[i].y;
	}*/
	points[0].x = 5, points[0].y = 5, points[1].x = 5, points[1].y = 15;
	points[2].x = -5, points[2].y = 25, points[3].x = 15, points[3].y = 25;
}

int main(int argc, char ** argv)
{
	int n = 4;
	Point *points = new Point[n];
	float **edges = new float*[n];
	Initialize_data(points, edges, n);
	Scene SC(-5);
	RigidBody RB(points, edges, n);
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
	//Инициализация GLUT
	glutInit(&argc, argv);
	//Задание размеров окна
	glutInitWindowSize(Width, Height);
	//Задание положения окна
	glutInitWindowPosition(100, 100);
	//Инициализация режимов
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	//Задание заголовка окна
	glutCreateWindow("Whirlpool");
	//Определить функцию изменения размеров
	//glutReshapeFunc(Reshape);
	//Определить функцию перерисовки
	glutDisplayFunc(Draw);	
	glutTimerFunc(50, Timer, 0);
	Initialize();
	//Вход в главный цикл GLUT
	glutMainLoop();
	return 0;
}
