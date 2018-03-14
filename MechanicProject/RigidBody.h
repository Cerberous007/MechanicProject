#pragma once
#include"SceneObject.h"
#include"Point.h"

class RigidBody :SceneObject
{
	float Width = 640, Height = 480;
public:
	int n = 4;
	float len[3];
	float mass[3];	
	void render();			
	Point* nodes = nullptr;
	float** edge = nullptr;	
	RigidBody() {}
	RigidBody(const RigidBody &rb);
	RigidBody(Point *_nodes, float **_edge, int _n) :nodes(_nodes), edge(_edge), n(_n) {}
	float length(Point a, Point b);
	void len_mass(float *mass, float *len, float **edge, int n);
};