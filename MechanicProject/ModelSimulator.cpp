#include"stdafx.h"
#include"ModelSimulator.h"
#include"RigidBody.h"
#include<ctime>
void ModelSimulator::run()
{
	for (;;)
	{
		for each (SceneObject obj in objects)
		{
			obj.render();
			obj.update();
		}
		
	}
}