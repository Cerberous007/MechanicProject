#include "stdafx.h"
#include "Physical.h"
#include<math.h>
#include"inverse.h"
#include"Point.h"



Physical::Physical(RigidBody rb)
{
	b = new double[n];
	double **A = new double*[n];
	invA = new double*[n];
	V = new double[n];
	delta = new double[n];

	for (int i = 0; i < n; i++)
	{
		invA[i] = new double[n];
		A[i] = new double[n];
	}

	distr = std::normal_distribution<>(0, disp);
	gen = std::mt19937(20018);

	for (int i = 0; i < n; i++)
	{		
		V[i] = 0;
		for (int j = 0; j < n; j++)
		{			
			A[i][j] = double(0);
			invA[i][j] = double(0);			
		}
	}

	for (int i = 0; i < n; i++)
		invA[i][i] = 1;
	A[0][0] = (rb.lentgh[0]* rb.lentgh[0])*(rb.mass[0]/3+rb.mass[1]+rb.mass[2]);
	A[0][3] = rb.lentgh[0] * (rb.mass[1] + rb.mass[2]);	
	A[1][1] = rb.mass[1] * rb.lentgh[1]* rb.lentgh[1]/3;
	A[2][2] = rb.mass[2] * rb.lentgh[2] * rb.lentgh[2]/3;
	A[3][0] = rb.lentgh[0] * (rb.mass[1] + rb.mass[2]);	
	A[3][3] = rb.mass[1] + rb.mass[0] + rb.mass[2];	
	printf("\n");
	printf("\n");
	inverse(A, invA, n);
	for (int i = 0; i < n; i++)
	{
			delete[] A[i];
	}
	delete[] A;
}



Physical::~Physical()
{
	/*for (int i = 0; i < n; i++)
	{
		delete[] A[i];
		delete[]invA[i];
	}
	delete[] A;
	delete[]invA;*/
}

void Physical::print()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%.8f ", invA[i][j]);
		}
		printf("\n");
	}
}

void Physical::mult()
{	
	//print();
	for (int i = 0; i < n; i++)
	{
		delta[i] = 0;
		for (int j = 0; j < n; j++)
		{
			delta[i] += b[j] * invA[i][j];
		}
	}
}

Physical& Physical::operator=(const Physical &a)
{
	distr = std::normal_distribution<>(0, disp);
	gen = std::mt19937(2018);
	b = new double[n];
	delta = new double[n];
	V = new double[n];
	invA = new double*[n];
	for (int i = 0; i < n; i++)
	{
		invA[i] = new double[n];
		V[i] = a.V[i];
		for (int j = 0; j < n; j++)
		{
			invA[i][j] = a.invA[i][j];
		}
	}
	return *this;
}

void Physical::update(RigidBody *rb)
{	

	double cos_teta = (rb->nodes[1].x - rb->nodes[0].x) / rb->lentgh[0];
	double cos_phi  = (rb->nodes[3].x - rb->nodes[1].x) / rb->lentgh[2];
	double cos_psa  = (rb->nodes[2].x - rb->nodes[1].x) / rb->lentgh[1];




	b[0] = - (rb->mass[1] * g * (rb->nodes[0].x - rb->nodes[1].x) + rb->mass[2] * g*(rb->nodes[0].x - rb->nodes[1].x) + rb->mass[0] * g*(rb->nodes[0].x - rb->nodes[1].x) / 2) + resist1 * V[0] * rb->lentgh[0];
	b[1] = -(rb->mass[2] * g * (rb->nodes[3].x - rb->nodes[1].x) / 2) - resist  *  V[1]* rb->lentgh[2];
	b[2] = -(rb->mass[1] * g * (rb->nodes[2].x - rb->nodes[1].x) / 2) - resist  * V[2]* rb->lentgh[1];
	b[3] = -resist*V[3];
	mult();
	for (int i = 0; i < n; i++)
	{

			V[i] += delta[i];
	}

	Point x(V[3], 0);

	rb->nodes[3] += x*delta_time + Point::rotate(rb->nodes[1], rb->nodes[0], delta_time*V[0]) - rb->nodes[1] + Point::rotate(rb->nodes[3], rb->nodes[1], delta_time*V[1]) - rb->nodes[3];
	rb->nodes[2] += x*delta_time + Point::rotate(rb->nodes[1], rb->nodes[0], delta_time*V[0]) - rb->nodes[1] + Point::rotate(rb->nodes[2], rb->nodes[1], delta_time*V[2]) - rb->nodes[2];
	rb->nodes[1] += x*delta_time + Point::rotate(rb->nodes[1], rb->nodes[0], delta_time*V[0]) - rb->nodes[1];
	rb->nodes[0] += x*delta_time;

}
