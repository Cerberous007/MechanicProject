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
	Point(float _x, float _y) : x(_x), y(_y), x_v(0), y_v(0), x_w(0), y_w(0) {}
	Point(float _x, float _y, float _x_v, float _y_v, float _x_w, float _y_w): x(_x), y(_y), x_v(_x_v), y_v(_y_v), x_w(_x_w), y_w(_y_w) {}
	Point &operator+=(const Point &x);
	Point &operator*=(const float x);
	Point &operator-=(const Point &x);
	void rotate(Point a, Point b, float phi);
};
