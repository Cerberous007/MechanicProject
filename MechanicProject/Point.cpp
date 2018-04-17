#include"stdafx.h"
#include"Point.h"
#include"math.h"
Point& Point::operator*=(const float a)
{
	x *= a; y *= a;
	return *this;
}
Point& Point::operator+=(const Point &a)
{
	x += a.x; y += a.y;
	return *this;
}
Point& Point::operator-=(const Point &a)
{
	x -= a.x; y -= a.y;
	return *this;
}
void Point::rotate(Point a, Point b, float phi_1)
{
	float x1 = a.x, y1 = a.y;
	a.x = (x1 - b.x)*cos(phi_1) - (y1 - b.y)*sin(phi_1) + b.x;
	a.y = (x1 - b.x)*sin(phi_1) - (y1 - b.y)*cos(phi_1) + b.y;
}