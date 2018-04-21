#pragma once
class Point
{
public:
	float x_v = 0;
	float y_v = 0;
	float x_w = 0;
	float y_w = 0;
	float x = 0;
	float y = 0;
	Point() {};
	Point(const Point &point);
	Point(float _x, float _y);
	Point(float _x, float _y, float _x_v, float _y_v, float _x_w, float _y_w);
	Point &operator+=(const Point &x);
	Point &operator*=(const float x);
	Point &operator-=(const Point &x);
	void rotate(Point a, Point b, float phi);
};
