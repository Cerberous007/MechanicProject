#pragma once
#include"SceneObject.h"
class Scene :SceneObject
{
public:
	void render();
	void update();
	float lvl = 0;
	Scene(){}
	Scene(float _lvl);
	Scene(const Scene &scene);
};
