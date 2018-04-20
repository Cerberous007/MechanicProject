#pragma once
#include"SceneObject.h"
#include"Point.h"


class RigidBody :SceneObject
{
public:
	void render();	
	void update();
	/*void print()
	{
		for (int i = 0; i < n; i++)
		{
			printf("%f %f\n", nodes[i].x, nodes[i].y);
		}
	}	*/
	int n = 1;
	Point* nodes = nullptr;
	float** edge = nullptr;	
	RigidBody() {}
	RigidBody(Point *_nodes, float **_edge, int _n) :nodes(_nodes), edge(_edge), n(_n) {}
};