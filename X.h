#pragma once
#include "geomet.h"


class X : public Geomet {

public:
	int start_x, start_y;
	int end_x, end_y;
	/*int mid_x, mid_y;
	int mid_r;
	*/
	X(const int& _start_x, const int& _start_y, const int& _end_x, const int& _end_y) {
		initialize(_start_x, _start_y, _end_x, _end_y);
	}
	void initialize(const int& _start_x, const int& _start_y, const int& _end_x, const int& _end_y);

	void draw();
};