#pragma once
#ifndef _BRESENHAM_LINE_H
#define _BRESENHAM_LINE_H

#include <iostream>
#include <graphics.h>


using std::cout;
using std::cin;

typedef unsigned short int index;

void BresenhamLine()
{
    int x1, y1, x2, y2, x, y, dx, dy, xinc, yinc, p0;
    char ans;


    do {
        cout << "Enter the value of x1 and y1 : ";
        cin >> x1 >> y1;
        cout << "Enter the value of x2 and y2: ";
        cin >> x2 >> y2;

        dx = abs(x2 - x1);
        dy = abs(y2 - y1);;

        xinc = (x2 > x1 ? 1 : -1);
        yinc = (y2 > y1 ? 1 : -1);

        x = x1; y = y1;
        p0 = 2 * dy - dx;

        // for decision parameters
        if (dx > dy) {
            for (int i = 0; i < dx; i++) {
                if (p0 < 0) {
                    x = x + xinc;
                    y = y;
                    p0 = p0 + 2 * dy;
                }
                else {
                    x = x + xinc;
                    y = y + yinc;
                    p0 = p0 + 2 * dy - 2 * dx;
                }
            }
        }
        else {
            for (int j = 0; j < dy; j++) {
                if (p0 < 0) {
                    x = x;
                    y = y + yinc;
                    p0 = p0 + 2 * dx;
                }
                else {
                    x = x + xinc;
                    y = y + yinc;
                    p0 = p0 + 2 * dx - 2 * dy;
                }
            }
        }

        cout << "Wanna continue? (y/n) ";
        cin >> ans;
    } while (ans == 'y');
}



#endif