#include "stdafx.h"
#include <iostream>
#include"inverse.h"


void inverse(double **a, double** b, int n)
{

	for (int i = 0; i < n; i++)
		gauseforward(b, a, n, i);

	for (int i = n - 1; i >= 0; i--)
		gauseback(b, a, n, i);

}
void gauseforward(double**b, double **a, int n, int k)
{
	int j, i;
	for (i = 0; (i < n) && (a[k][k] != 0); i++)
	{
		b[k][i] = b[k][i] / a[k][k];
		a[k][i] = a[k][i] / a[k][k];
	}
	for (i = k + 1; i < n; i++) {
		double cur = a[i][k];
		for (j = 0; j < n; j++)
		{
			b[i][j] = b[i][j] - cur * b[k][j];
			a[i][j] = a[i][j] - cur * a[k][j];

		}
		/*printf("a матрица\n");
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				printf("%f ", a[i][j]);
			printf("\n");
		}*/
	}

}
void gauseback(double **b, double **a, int n, int k)
{
	int j, i;
	for (i = n - 1; (i >= 0) && (a[k][k] != 0); i--)
	{
		b[k][i] = b[k][i] / a[k][k];
		a[k][i] = a[k][i] / a[k][k];
	}
	for (i = k - 1; i >= 0; i--)
	{
		double cur = a[i][k];
		for (j = n - 1; j >= 0; j--)
		{
			b[i][j] = b[i][j] - cur * b[k][j];
			a[i][j] = a[i][j] - cur * a[k][j];
		}
	}
}