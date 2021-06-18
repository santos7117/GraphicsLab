#pragma once
#ifndef _DDA_LINE_H
#define _DDA_LINE_H

#include <iostream>
#include <math.h>
#include <graphics.h>

using std::cout;
using std::cin;
using std::endl;

typedef unsigned short int index;

void DDALine()
{
	char ans;
	float x, y, x1, y1, x2, y2, dx, dy, step;

	do {
		cout << "Enter the value of x1 and y1 : ";
		cin >> x1 >> y1;
		cout << "Enter the value of x2 and y2: ";
		cin >> x2 >> y2;

		dx = abs(x2 - x1);
		dy = abs(y2 - y1);

		step = (dx >= dy) ? dx : dy;

		dx = dx / step;
		dy = dy / step;

		// cast into int coordinates and plot
		for (index i{ 0 }, x=x1, y=y1; i <= step; ++i)
		{
			putpixel(static_cast<int>(x), static_cast<int>(y), colors::GREEN);

			x = x + dx;
			y = y + dy;
		}
		
		cout << "Wanna continue? (y/n) ";
		cin >> ans;
	} while (ans == 'y');
}



#endif