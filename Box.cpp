#include "Box.h"

void Box::initialize(const int& _area, const int& _start_x, const int& _start_y) {
	start_x = _start_x;
	start_y = _start_y;
	area = _area;
}

void Box::draw() {
	drawsquare(area, start_x, start_y, 0.0f, 0.0f, 0.0f);
}