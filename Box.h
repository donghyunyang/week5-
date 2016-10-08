#pragma once
#include "geomet.h"

void drawsquare(const int& edge, const int& i0, const int& j0, const float& red, const float& green, const float& blue);

class Box : public Geomet {

public:
	int start_x, start_y,area;


	Box(const int& _area, const int& _start_x, const int& _start_y) {
		initialize(_area,_start_x, _start_y);
	}
	void initialize(const int& _area, const int& _start_x, const int& _start_y);
	void draw();
};