#pragma once
class Point
{
public:

	double x = 0;
	double y = 0;
	Point() {};
	Point(const Point &point);
	Point(double _x, double _y);
	Point(double _x, double _y, double _x_v, double _y_v, double _x_w, double _y_w);
	Point &operator+=(const Point &a);
	Point &operator*(const double a);
	Point &operator-=(const Point &a);
	Point &operator+(const Point &a);
	Point &operator-(const Point &a);
	static Point rotate(Point a, Point b, double phi);
};
