#include"stdafx.h"
#include"RigidBody.h"
#include <glut.h>
#include<math.h>


RigidBody::RigidBody(const RigidBody &rb):SceneObject()
{
	edge = new float*[rb.n];
	nodes = new Point[rb.n];
	n = rb.n;
	for (int i = 0; i < rb.n; i++)
	{
		edge[i] = new float[rb.n];
		nodes[i] = rb.nodes[i];
		for (int j = 0; j < rb.n; j++)
		{
			edge[i][j] = rb.edge[i][j];
		}
	}
}


void RigidBody::render()
{	
	float x, y;
	//Очистка цветового буфера
	//glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(0, 255, 0);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < n; i++)
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
	glFlush();	
}

void RigidBody::update()
{

}