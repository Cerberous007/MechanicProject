#pragma once
#include"RigidBody.h"
#include"SceneObject.h"
#include"Scene.h"
#include"Physical.h"
#include<list>
class ModelSimulator
{
private:
		
public:	
	Physical ph;
	RigidBody rb;
	Scene sc;
	ModelSimulator(RigidBody &_rb, Scene &_scene);	
	void render();
	void update();
};
