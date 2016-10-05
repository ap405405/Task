#pragma once
#include "GeometryObj.h"
class Square : public GeometryObj {
private:
	int center_x=300, center_y=350;
	int x_edge=350, y_edge=400;
public:
	void initialize(const int& _c_x, const int& _c_y, const int&_e_x, const int&_e_y) {
		center_x = _c_x;
		center_y = _c_y;
		x_edge = _e_x;
		y_edge = _e_y;
	}
	void draw() {
		for (int i = center_x; i <= x_edge; i++)
		{
			drawPixel(i, center_y, 1.0f, 0.0f, 0.0f);
			drawPixel(i, y_edge, 1.0f, 0.0f, 0.0f);
		}
		for (int j = center_y; j <= y_edge; j++)
		{
			drawPixel(center_x, j, 1.0f, 0.0f, 0.0f);
			drawPixel(x_edge, j, 1.0f, 0.0f, 0.0f);
		}
	}
};