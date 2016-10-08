#include <GLFW/glfw3.h>
#include <cstring>
#include <stdlib.h>		  // srand, rand
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include "math.h"
#include <windows.h>
#include <stdbool.h>
#include "Geomet.h"
#include "Line.h"
#include "Box.h"
#include "circle.h"
#include "triangle.h"
#include "downarrow.h"
#include "uparrow.h"
#include "rightarrow.h"
#define pi 3.14159265358979
const int width = 1366;
const int height = 768;

float* pixels = new float[width*height * 3];// �ȼ��� �迭�� �������ݴϴ�. �ػ� x 3(rgb)�Դϴ�.
double xpos, ypos;
Geomet **my_object = new Geomet*[20];
bool incircle(const int& i,const int& j,const int& r)
{
	if ((xpos - i)*(xpos - i) + (ypos - j)*(ypos - j) <= r*r)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void drawPixel(const int& i, const int& j, const float& red, const float& green, const float& blue)//�ȼ��迭�� ��(rgb)�� �ִ� �����Դϴ�.
{
	pixels[(i + width* j) * 3 + 0] = red;
	pixels[(i + width* j) * 3 + 1] = green;
	pixels[(i + width* j) * 3 + 2] = blue;
}

void drawLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{

	if (i1 - i0 == 0)//���� �Լ��� �и� 0�̸� �� x2-x1 ���̰� 0�̸� ������ ���Ƿ� 0�϶� y�ุ�׸��°�������.
	{
		for (int i = j0;i < j1;i++)
		{
			drawPixel(i1, i, red, green, blue);
		}
	}
	else if ((j1 - j0) != 0)//���Ⱑ 0�̾ƴ� �������ϰ�� 
	{
		for (int i = i0; i < i1; i++)
		{
			const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;

			drawPixel(i, j, red, green, blue);// i���� j���� rgb������ �׸���
			drawPixel(i, j - 1, red, green, blue);drawPixel(i, j + 1, red, green, blue);//�������� �ȼ����� �������⶧���� �߰����־����ϴ�.

		}
	}
	else//�����ϰ�� 
	{
		for (int i = i0; i < i1; i++)
		{
			const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;

			drawPixel(i, j, red, green, blue);// i���� j���� rgb������ �׸���

		}
	}
}
void thickLine(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue)
{

	if (i1 - i0 == 0)//���α׸���
	{
		for (int i = j0;i < j1;i++)
		{
			for (int j = 0;j < 10;j++)//�����ȼ����� x���� 10��ŭ �������� ����ϴ�.(�β������°���)
			{
				drawPixel(i1 + j, i, red, green, blue);
			}
		}
	}
	else if ((j1 - j0) != 0)
	{
		for (int i = i0; i < i1; i++)
		{
			const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;
			for (int k = 0;k < 10;k++)
			{
				drawPixel(i, j, red, green, blue);// i���� j���� rgb������ �׸���
				drawPixel(i, j - k, red, green, blue);drawPixel(i, j + k, red, green, blue);
			}
		}
	}
	else
	{
		for (int i = i0; i < i1; i++)
		{
			const int j = (j1 - j0)*(i - i0) / (i1 - i0) + j0;

			drawPixel(i, j, red, green, blue);// i���� j���� rgb������ �׸���

		}
	}
}
void drawdownarrow(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue) {
	drawLine(i0, j0, i1, j1, red, green, blue);
	drawLine(i1 - 30, j0 + 30, i1, j0, red, green, blue);
	drawLine(i1, j0, i1 + 30, j0 + 30, red, green, blue);

}
void drawrightarrow(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue) {
	drawLine(i0, j0, i1, j1, red, green, blue);
	drawLine(i1 - 30, j1 + 30, i1, j1, red, green, blue);
	drawLine(i1 - 30, j1 - 30, i1, j1, red, green, blue);

}
void drawcircle(const int& x1, const int& y1, const int& r, const float& red, const float& green, const float& blue)
{
	float i = 0.0;
	float rad_to_deg = 0.0;
	float degree = 360.0;
	int x2 = 0, y2 = 0;

	
	for (degree = 0;degree < 360;degree++)
	{
		rad_to_deg = degree*(pi / 180);
		x2 = x1 + r*sin(rad_to_deg);
		y2 = y1 + r*cos(rad_to_deg);
		drawPixel(x2, y2, red, green, blue);
		drawPixel(x2 + 1, y2, red, green, blue);
		drawPixel(x2, y2 - 1, red, green, blue);
	}


}
void drawuparrow(const int& i0, const int& j0, const int& i1, const int& j1, const float& red, const float& green, const float& blue) {
	drawLine(i0, j0, i0, j1, red, green, blue);
	drawLine(i0 - 30, j1 - 30, i0, j1, red, green, blue);
	drawLine(i0, j1, i0 + 30, j1 - 30, red, green, blue);

}
void drawtriangle(const int& i0, const int& j0, const float& red, const float& green, const float& blue) {
	drawLine(i0, j0, i0 + 80, j0, red, green, blue);
	drawLine(i0, j0, i0 + 40, j0 + 80, red, green, blue);
	drawLine(i0 + 40, j0 + 80, i0 + 80, j0, red, green, blue);

}
void drawsquare(const int& area, const int& i0, const int& j0, const float& red, const float& green, const float& blue)
{
	drawLine(i0, j0, i0 + area, j0, red, green, blue);
	drawLine(i0 + area, j0, i0 + area, j0 + area, red, green, blue);
	drawLine(i0, j0 + area, i0 + area, j0 + area, red, green, blue);
	drawLine(i0, j0, i0, j0 + area, red, green, blue);

}
void drawfilledsqaure()
{

}
void drawtriangle()
{
	drawLine(100, 100, 200, 250, 1.0f, 0.0f, 0.0f);
	drawLine(100, 100, 300, 100, 1.0f, 0.0f, 0.0f);
	drawLine(200, 250, 300, 100, 1.0f, 0.0f, 0.0f);
	//�ﰢ�� �׸���
}
void pentagon()
{
	drawLine(425, 175, 500, 250, 0.0f, 0.0f, 0.0f);
	drawLine(425, 175, 450, 100, 0.0f, 0.0f, 0.0f);
	drawLine(450, 100, 550, 100, 0.0f, 0.0f, 0.0f);
	drawLine(550, 100, 575, 175, 0.0f, 0.0f, 0.0f);
	drawLine(500, 250, 575, 175, 0.0f, 0.0f, 0.0f);
}
void circle20()
{
	float r, g, b;

	for (int i = 200;i < 768;i += 150)
	{
		for (int j = 200;j < 1366;j += 250)
		{
			if (incircle(j, i, 70) == true)
			{
				r = 1.0f;
				g = 0.0f;
				b = 0.0f;

			}
			else
			{
				r = 1.0f;
				g = 0.0f;
				b = 0.0f;
			}
			drawcircle(j, i, 70, r, g, b);

		}
	}
}
void rect20(const int& area, const int& i0, const int& j0, const float& red, const float& green, const float& blue)
{
	if (xpos <= i0 + area && xpos >= i0 && ypos <= j0 + area && ypos >= j0) {
		drawLine(i0, j0, i0 + area, j0, 1.0f, 0.0f, 0.0f);
		drawLine(i0 + area, j0, i0 + area, j0 + area, 1.0f, 0.0f, 0.0f);
		drawLine(i0, j0 + area, i0 + area, j0 + area, 1.0f, 0.0f, 0.0f);
		drawLine(i0, j0, i0, j0 + area, 1.0f, 0.0f, 0.0f);
	}
	else {
		drawLine(i0, j0, i0 + area, j0, 0.0f, 0.0f, 1.0f);
		drawLine(i0 + area, j0, i0 + area, j0 + area, 0.0f, 0.0f, 1.0f);
		drawLine(i0, j0 + area, i0 + area, j0 + area, 0.0f, 0.0f, 1.0f);
		drawLine(i0, j0, i0, j0 + area, 0.0f, 0.0f, 1.0f);

	}


}
Geomet circle2;
void drawOnPixelBuffer()
{
	
	float r, g, b = 0.0f;
	ypos = height - ypos;
	std::fill_n(pixels, width*height * 3, 1.0f);	// white background
	circle2.draw();
	for (int i = 0; i <22; i++) {
		my_object[i]->draw();
	}
	
}

int main(void)
{
	srand((unsigned int)time(NULL));
	for (int i = 0;i < 2;i++)
	{
		my_object[i] = new Line(150+i*750,610,240+i*750, 690);
	}
	for (int i =2;i < 4;i++)
	{
		my_object[i] = new Box(80,410+((i-2)*250), 610);
	}
	for (int i = 4;i < 6;i++)
	{
		my_object[i] = new Circle(1200+((i-4)*370),650-((i-4)*150),40);
	}
	for (int i = 6; i < 8;i++)
	{
		if(i==6)
		my_object[i] = new Line(160, 310, 230, 400);
		else if(i==7)
			my_object[i] = new Line(160, 400, 230, 310);
	}
	for (int i = 8; i < 10;i++)
	{
		if (i == 8)
			my_object[i] = new Line(660, 310, 730, 400);
		else if (i == 9)
			my_object[i] = new Line(660, 400, 730, 310);
	}
	for (int i= 10;i < 15;i++)
	{
		my_object[i] = new triangle(160 + 250 * (i-10),180, 75 + 90 * (i-10), 250);
	}
	for (int i = 15;i < 17;i++)
	{
		my_object[i] = new downarrow(950 + (250* (i-15)), 300, 950 + (250 * (i-15)), 400);
	}
	for (int i = 17;i < 21;i++)
	{
		my_object[i] = new uparrow(450 + (250 * (i-17)), 450, 450 + (250 *(i-17)), 550);
	}
	for (int i = 17;i < 21;i++)
	{
		my_object[i] = new uparrow(450 + (250 * (i - 17)), 450, 450 + (250 * (i - 17)), 550);
	}
	for (int i = 21;i < 22;i++)
	{
		my_object[i] = new rightarrow(320 +90, 350, 420+90, 350);
	}
	//for(int i=5;)
	
	GLFWwindow* window;
	
	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(width, height, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	glClearColor(1, 1, 1, 1); // while background

							  /* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		glfwGetCursorPos(window, &xpos, &ypos);
		
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);
		drawOnPixelBuffer();

		//TODO: RGB struct

		//Make a pixel drawing function
		//Make a line drawing function
		glDrawPixels(width, height, GL_RGB, GL_FLOAT, pixels);

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	glfwTerminate();

	delete[] pixels; // or you may reuse pixels array 

	return 0;
}

