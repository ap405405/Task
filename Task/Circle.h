#pragma once
#include "math.h"
#include "GeometryObj.h"
class Circle : public GeometryObj {
private:
	int center_x, center_y;
	int r_radius;
public:
	Circle(const int& _c_x, const int& _c_y, const int&_r_r) {
		initialize(_c_x, _c_y, _r_r);
	}

	void initialize(const int& _c_x, const int& _c_y, const int&_r_r) {
		center_x = _c_x;
		center_y = _c_y;
		r_radius = _r_r;
	}


	bool isInsideCircle(const int i0, const int j0, const int i, const int j, const int r)
	{
		const int f = (i - i0)*(i - i0) + (j - j0)*(j - j0) - r*r;
		if (f > 50 || f < -50) return false;
		else return true;
	}
	void draw() {

		for (int j = center_y - r_radius; j <= center_y + r_radius; j++)
		{
			for (int i = center_x - r_radius; i <= center_x + r_radius; i++)
			{
				if (isInsideCircle(center_x, center_y, i, j, r_radius) == true) {
					drawPixel(i, j, 1.0f, 0.0f, 0.0f);
					drawPixel(i - 1, j, 1.0f, 0.0f, 0.0f);
					drawPixel(i + 1, j, 1.0f, 0.0f, 0.0f);
					drawPixel(i, j - 1, 1.0f, 0.0f, 0.0f);
					drawPixel(i, j + 1, 1.0f, 0.0f, 0.0f);

				}
			}
		}
	}
};