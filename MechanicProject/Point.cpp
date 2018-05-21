#include"stdafx.h"
#include"Point.h"
#include"math.h"
Point::Point(double _x, double _y) : x(_x), y(_y), x_v(0), y_v(0), x_w(0), y_w(0) {}
Point::Point(double _x, double _y, double _x_v,
	double _y_v, double _x_w, double _y_w)
{
	x = _x, y = _y, x_v = _x_v, y_v = _y_v, x_w = _x_w, y_w = _y_w;
}
Point::Point(const Point &point)
{
	x = point.x;
	y = point.y;
	y_v = point.y_v;
	x_v = point.x_v;
	x_w = point.x_w;
	y_w = point.y_w;
}
Point& Point::operator*(const double a)
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
Point& Point::operator+(const Point &a)
{
	x += a.x; y += a.y;
	return *this;
	
}
Point& Point::operator-(const Point &a)
{
	x -= a.x; y -= a.y;
	return *this;
}
Point Point::rotate(Point a, Point b, double phi_1)
{
	Point c;	
	c.x = (a.x - b.x)*cos(phi_1) - (a.y - b.y)*sin(phi_1) + b.x;
	c.y = (a.x - b.x)*sin(phi_1) + (a.y - b.y)*cos(phi_1) + b.y;
	return c;
}
