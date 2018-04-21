#include"stdafx.h"
#include"ModelSimulator.h"
#include"RigidBody.h"
#include <iostream>
#include <Windows.h>
#include<glut.h>
//#include <ctime>
//void sleep(const size_t seconds)
//{
//	clock_t start = clock();
//	while ((double)(clock() - start) / CLOCKS_PER_SEC < seconds);
//}
ModelSimulator::ModelSimulator(RigidBody &_rb, Scene &_scene)
{
	rb =RigidBody (_rb);
	sc = Scene(_scene);
}
void ModelSimulator::render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	sc.render();
	rb.render();
}
void ModelSimulator::run()
{
	render();
	Sleep(delta_t);
	/*for (;;)
	{
		render();
		Sleep(delta_t);
	}*/
}