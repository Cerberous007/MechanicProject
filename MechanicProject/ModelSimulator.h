#pragma once
#include"RigidBody.h"
#include"Scene.h"
#include<list>
class ModelSimulator
{
public:
	std::list<SceneObject> objects;
	ModelSimulator() {}
	//ModelSimulator(RigidBody _rb, Scene _scene):objects.insert(_rb), {}
	double delta_t = 0.1;
	void run();
};
