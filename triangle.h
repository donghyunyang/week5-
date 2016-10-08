#pragma once
#include "geomet.h"
void drawtriangle(const int& i0, const int& j0, const float& red, const float& green, const float& blue);

class triangle : public Geomet {
public:
	int start_x, start_y;
	int end_x, end_y;
	triangle(const int& _start_x, const int& _start_y, const int& _end_x, const int& _end_y) {
		initialize(_start_x, _start_y, _end_x, _end_y);
	}
	void initialize(const int& _start_x, const int& _start_y, const int& _end_x, const int& _end_y);

	void draw();
};