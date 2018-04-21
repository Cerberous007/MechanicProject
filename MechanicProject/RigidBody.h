#pragma once
#include"SceneObject.h"
#include"Point.h"


class RigidBody :SceneObject
{
public:
	void render();	
	void update();		
	int n = 1;
	Point* nodes = nullptr;
	float** edge = nullptr;	
	RigidBody() {}
	RigidBody(const RigidBody &rb);
	RigidBody(Point *_nodes, float **_edge, int _n) :nodes(_nodes), edge(_edge), n(_n) {}
};