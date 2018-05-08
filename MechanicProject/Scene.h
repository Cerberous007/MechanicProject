#pragma once
#include"SceneObject.h"
class Scene :SceneObject
{
	float Width = 640, Height = 480;
public:
	void render();	
	float lvl = 0;
	Scene(){}
	Scene(float _lvl);
	Scene(const Scene &scene);
};
