#include "geomet.h"

void Geomet::draw()
{
	//circle20();
	for (int i = 0;i < 4;i++)
	{
		for (int j = 0;j < 5;j++)
		{
			rect20(130, 140+((j)*250), 140+(i*150), 0.0f, 0.0f, 0.0f);
		}
	}
	
}
