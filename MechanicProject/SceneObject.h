#pragma once
class SceneObject
{
protected:
	SceneObject() {}
public:
	virtual void render()  {};
	virtual void update()  {};
};