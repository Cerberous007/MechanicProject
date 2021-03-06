#pragma once
#include "RigidBody.h"
#include "Scene.h"
#include<random>


static class Physical
{
public:	
	double g = 9.8;
	double delta_time = 0.01;
	double resist = 0.01;
	double resist1 = 0.25;
	const int n = 4;
	double **A = nullptr;
	double **invA=nullptr;
	double *b = nullptr;
	double *delta = nullptr;
	double *V = nullptr;
	const double disp = 0.1;
	std::normal_distribution<> distr;
	std::mt19937 gen;
	void update(RigidBody *rb);	
	Physical() {}
	Physical &operator=(const Physical &a);
	Physical(RigidBody rb);
	~Physical();	
	void print();
	void mult();
};

