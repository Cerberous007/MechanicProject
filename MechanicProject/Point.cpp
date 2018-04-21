#include"stdafx.h"
#include"Point.h"
#include"math.h"
Point::Point(float _x, float _y) : x(_x), y(_y), x_v(0), y_v(0), x_w(0), y_w(0) {}
Point::Point(float _x, float _y, float _x_v, float _y_v, float _x_w, float _y_w) : x(_x), y(_y), x_v(_x_v), y_v(_y_v), x_w(_x_w), y_w(_y_w) {}
Point::Point(const Point &point)
{
	float x = point.x;
	float y = point.y;
	float y_v = point.y_v;
	float x_v = point.x_v;
	float x_w = point.x_w;
	float y_w = point.y_w;
}
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