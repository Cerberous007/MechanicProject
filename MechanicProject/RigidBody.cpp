#include"stdafx.h"
#include"RigidBody.h"
#include <glut.h>
#include<math.h>


double RigidBody::lengt(Point a, Point b)
{
	return sqrtf((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

RigidBody::RigidBody(Point *_nodes, double **_edge, int _n)
{
	nodes = _nodes;
	edge = _edge;
	n = _n;
	for (int i = 0, k = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (edge[i][j] != 0)
			{
				lentgh[k] = lengt(nodes[i], nodes[j]);
				mass[k] = edge[i][j];
				k++;
			}
		}
	}
}

RigidBody::RigidBody(const RigidBody &rb):SceneObject()
{	
	edge = new double*[rb.n];
	nodes = new Point[rb.n];
	n = rb.n;
	for (int i = 0; i < rb.n; i++)
	{
		edge[i] = new double[rb.n];
		nodes[i] = rb.nodes[i];
		for (int j = 0; j < rb.n; j++)
		{
			edge[i][j] = rb.edge[i][j];
		}
	}
	for (int i = 0, k=0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (edge[i][j] != 0)
			{
				lentgh[k] = lengt(nodes[i], nodes[j]);
				mass[k] = edge[i][j];
				k++;
			}
		}
	}
}


void RigidBody::render()
{	
	float x, y;	
	glColor3d(0, 255, 0);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i <n; i++)
	{
		x = nodes[i].x;
		y = nodes[i].y;
		for (int j = 0; j < n; j++)
		{
			if (edge[i][j]!=0)
			{
				glVertex2d(x, y);
				glVertex2d(nodes[j].x, nodes[j].y);
				glTranslated(x, y, 0);				
			}
		}
	}	
	glEnd();		
}