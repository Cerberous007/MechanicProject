#include"stdafx.h"
#include"Scene.h"
#include <glut.h>

Scene::Scene(float _lvl)
{
	lvl = _lvl;
}
Scene::Scene(const Scene &scene)
{
	lvl = scene.lvl;
}
void Scene::render()
{	
	//Установка цвета отображения
	glColor3d(0, 0, 0);
	//Рисование осей
	glBegin(GL_LINES);
	//Установка вершин
	glVertex2d(-60., .0);
	glVertex2d(60., .0);
	glVertex2d(.0, -60.);
	glVertex2d(.0, 60.);
	//Завершить рисование осей
	glEnd();	
	glColor3d(255, 0, 0);	
	glBegin(GL_LINES);	
	glVertex2d(-50, lvl);
	glVertex2d(50, lvl);
	glEnd();	
}


