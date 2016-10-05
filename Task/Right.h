#pragma once
#include "GeometryObj.h"
class Right : public GeometryObj
{
private:
	int start_x = 50, start_y = 150;
	int end_x = 100, end_y = 150;
public:
	void initialize(const int& _start_x, const int & _start_y, const int& _end_x, const int& _end_y) {
		start_x = _start_x;
		start_y = _start_y;
		end_x = _end_x;
		end_y = _end_y;
	}
	void draw() {
		drawLine(start_x, start_y, end_x, end_y, 1.0f, 0.0f, 0.0f);
		drawLine(start_x+50, start_y, end_x -15, end_y + 15, 1.0f, 0.0f, 0.0f);
		drawLine(start_x+50, start_y, end_x - 15, end_y - 15, 1.0f, 0.0f, 0.0f);
	}
};