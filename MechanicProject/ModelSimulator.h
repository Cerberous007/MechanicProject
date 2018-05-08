#pragma once
#include"RigidBody.h"
#include"SceneObject.h"
#include"Scene.h"
#include<list>
class ModelSimulator
{
private:
		
public:	
	RigidBody rb;
	Scene sc;
	ModelSimulator(RigidBody &_rb, Scene &_scene);	
	void render();
	void update();
};
