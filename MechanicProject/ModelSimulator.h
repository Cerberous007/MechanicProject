#pragma once
#include"RigidBody.h"
#include<list>
class ModelSimulator
{
public:
	std::list<SceneObject> objects;
	double delta_t = 0.1;
	void run();
};
