#pragma once
#include"RigidBody.h"
#include"SceneObject.h"
#include"Scene.h"
#include<list>
class ModelSimulator
{
private:
	void render();
public:
	//std::list<SceneObject> objects;	
	//ModelSimulator() {}
	RigidBody rb;
	Scene sc;
	ModelSimulator(RigidBody &_rb, Scene &_scene);	
	double delta_t = 5000;
	void run();
};
