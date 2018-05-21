#include"stdafx.h"
#include"Point.h"
#include"math.h"
Point::Point(double _x, double _y) : x(_x), y(_y) {}
Point::Point(double _x, double _y, double _x_v,
	double _y_v, double _x_w, double _y_w)
{
	x = _x, y = _y;
}
Point::Point(const Point &point)
{
	x = point.x;
	y = point.y;

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
