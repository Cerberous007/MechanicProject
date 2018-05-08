#pragma once
#include "RigidBody.h"
#include "Scene.h"

static class Physical:RigidBody
{
public:	
	int n = 4;
	float **A = NULL;	
	float *q = NULL;
	static void update(RigidBody rb, Scene sc);		
	Physical(RigidBody rb)
	{
		float **A = new float*[n];
		for (int i = 0; i < n; i++)
		{
			A[i] = new float[n];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{

			}
		}
	}
};

