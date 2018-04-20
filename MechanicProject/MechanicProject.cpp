// MechanicProject.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
#include"RigidBody.h"
#include"Point.h"
#include"Scene.h"
#include <glut.h>
#include <memory>

float Width = 640, Height = 480;
RigidBody* L_RB;
Scene* L_S;

void Reshape(int width, int height)
{
	//Установка порта вывода
	//glViewport(0, 0, width, height);
	//Режим матрицы проекций
	glMatrixMode(GL_PROJECTION);
	//Единичная матрица
	glLoadIdentity();
	//Установка двумерной ортографической системы координат 
	gluOrtho2D(-50., 50., -50., 50.);
	//Режим видовой матрицы
	glMatrixMode(GL_MODELVIEW);
}

//Функция визуализации
void Draw(void)
{
	L_RB->render();

}

int main(int argc, char ** argv)
{
	int n = 3;
	Point *points = new Point[n];
	float **edges = new float*[n];
	for (int i = 0; i < n; i++)
	{
		edges[i] = new float[n];
	}
	puts("EDGES");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i < j)
				std::cin >> edges[i][j];
			else
				edges[i][j]=0;
		}		
	}
	puts("Coords");
	for (int i = 0; i < n; i++)
	{
		std::cin >> points[i].x;
		std::cin >> points[i].y;
	}	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%lf ", edges[i][j]);
		}
		printf("\n");
	}
	std::auto_ptr<RigidBody> RB(new RigidBody(points, edges, n));
	L_RB = RB.get();	
	//Инициализация GLUT
	glutInit(&argc, argv);
	//Задание размеров окна
	glutInitWindowSize(Width, Height);
	//Задание положения окна
	glutInitWindowPosition(100, 100);
	//Инициализация режимов
	glutInitDisplayMode(GLUT_RGB);
	//Задание заголовка окна
	glutCreateWindow("Whirlpool");
	//Определить функцию изменения размеров
	glutReshapeFunc(Reshape);
	//Определить функцию перерисовки
	glutDisplayFunc(Draw);	
	//Определить цвет очистки
	glClearColor(255, 255, 255, 1);
	//Вход в главный цикл GLUT
	glutMainLoop();
	return 0;
}
