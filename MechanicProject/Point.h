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
	Point(float _x, float _y) : x(_x), y(_y) {}
	Point &operator+=(const Point &x);
	Point &operator*=(const float x);
	Point &operator-=(const Point &x);
	void rotate(Point a, Point b, float phi);
};
