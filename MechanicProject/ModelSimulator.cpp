#include"stdafx.h"
#include"ModelSimulator.h"
#include <iostream>
#include<glut.h>

ModelSimulator::ModelSimulator(RigidBody &_rb, Scene &_scene)
{
	ph = Physical(_rb);
	rb =RigidBody (_rb);
	sc = Scene(_scene);
}
void ModelSimulator::render()
{	
	glClear(GL_COLOR_BUFFER_BIT);
	sc.render();
	rb.render();
	glutSwapBuffers();
}

void ModelSimulator::update()
{	
	if (rb.nodes[0].y > sc.lvl)
	{
		for (int i = 0; i < rb.n; i++)
		{
			if (rb.nodes[0].y != sc.lvl)
				rb.nodes[i].y--;
		}
	}
	else
	{
		ph.update(&rb);
	}
}