#include <iostream>
#include <string>
#include <vector>
#include "MyPainter2D.h"


MyPainter2D Painter_2D;

class Box {
private:
	int center_x=75, center_y=375;
	int x_edge=50, y_edge=50;
public:
	
	void draw() {
		Painter_2D.drawLine(center_x - x_edge / 2, center_y - y_edge / 2, center_x + x_edge / 2, center_y - y_edge / 2, 1.0f, 0.0f, 0.0f);
		Painter_2D.drawLine(center_x + x_edge / 2, center_y - y_edge / 2, center_x + x_edge / 2, center_y + y_edge / 2, 1.0f, 0.0f, 0.0f);
		Painter_2D.drawLine(center_x - x_edge / 2, center_y + y_edge / 2, center_x + x_edge / 2, center_y + y_edge / 2, 1.0f, 0.0f, 0.0f);
		Painter_2D.drawLine(center_x - x_edge / 2, center_y - y_edge / 2, center_x - x_edge / 2, center_y + y_edge / 2, 1.0f, 0.0f, 0.0f);
	}
};

class Circle  {
private:
	int center_x=275, center_y=150;
	int r_radius=60;
	float red = 1.0f, green = 0.0, blue = 0.0;
public:
	void draw() {
		for (int a = 0; a <= 2 * r_radius; a++)
		{
			for (int b = 0; b <= 2 * r_radius; b++)
			{
				int f = (r_radius - b)*(r_radius - b) + (r_radius - a)*(r_radius - a) - r_radius*r_radius;
				if (f < 0 && -200 < f)
				{
					Painter_2D.drawPixel(center_x - r_radius + b, center_y - r_radius + a, red, green, blue);
				}
			}
		}
	}
};

class GeometricObjectInterface {
public:
	virtual void draw()=0;
};

template <class T_OPERATION>
class GeomericObject :public GeometricObjectInterface {
public:
	void draw() {
		T_OPERATION operation;
		operation.draw();
	}
};


int main() {
	Painter_2D.initialize();

	while (Painter_2D.Close())
	{
		Painter_2D.preprocessing();

		std::vector<GeometricObjectInterface*> obj_list;
		obj_list.push_back(new GeomericObject<Box>);
		obj_list.push_back(new GeomericObject<Circle>);

		for (auto itr : obj_list) {
			(itr)->draw();
		}
		Painter_2D.postprocessiong();
	}
	return 0;
}
