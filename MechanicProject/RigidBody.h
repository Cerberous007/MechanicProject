#pragma once
#include"SceneObject.h"
#include"Point.h"

class RigidBody :SceneObject
{
	double Width = 640, Height = 480;
public:
	int n = 4;
	double lentgh[3];
	double mass[3];
	void render();			
	Point* nodes = nullptr;
	double** edge = nullptr;
	RigidBody() {}
	RigidBody(const RigidBody &rb);
	RigidBody(Point *_nodes, double **_edge, int _n);
	double lengt(Point a, Point b);
};