#pragma once
#include"SceneObject.h"
class Scene :SceneObject
{
	void render();
	void update();
	float lvl = 0;
	Scene(float _lvl) :lvl(_lvl) {};
};
