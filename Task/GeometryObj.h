#pragma once
#include <iostream>
#include "Draw.h"
class GeometryObj {
public:
	virtual void draw() {
		std::cout << "Geometry Obj" << std::endl;
	}
};
