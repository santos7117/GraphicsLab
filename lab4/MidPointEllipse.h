#pragma once
#ifndef _MID_POINT_ELLIPSE_H
#define _MID_POINT_ELLIPSE_H

#include <iostream>
#include <graphics.h>


using std::cout;
using std::cin;

void MidPointEllipse()
{
    char ans;
    float x,y,xc,yc,rx,ry,p0,p;

    do {
        cout << "Enter center of ellipse: ";
        cin >> xc >> yc;
        cout << "Enter (rx, ry): ";
        cin >> rx >> ry;

        x = 0;
        y = ry;

        p = ry * ry - rx * rx * ry + (rx * rx) / 4;

        // for first region
        do{
            putpixel( x+xc, y+yc, WHITE);
            putpixel( x+xc,-y+yc, WHITE);
            putpixel(-x+xc,-y+yc, WHITE);
            putpixel(-x+xc, y+yc, WHITE);

            if (p < 0)
                p = p + 2 * ry * ry * x + ry * ry;
            else {
                y--;
                p = p + 2 * ry * ry * x - 2 * rx * rx * y + ry * ry;
            }
            x++;

        } while (2 * ry * ry * x < 2 * rx * rx * y);

        // for second region
        p = ry * ry * (x + 0.5) * (x + 0.5) + 
            rx * rx * (y - 1) * (y - 1) - 
            rx * rx * ry * ry;

        do{
            putpixel( x+xc, y+yc, WHITE);
            putpixel( x+xc,-y+yc, WHITE);
            putpixel(-x+xc,-y+yc, WHITE);
            putpixel(-x+xc, y+yc, WHITE);

            if (p > 0)
                p = p - 2 * rx * rx * y + rx * rx;
            else {
                x++;
                p = p + 2 * ry * ry * x - 2 * rx * rx * y + rx * rx;
            }
            y--;

        }while(y != 0);

        cout << "Wanna continue? (y/n) ";
        cin >> ans;
    } while (ans == 'y');

}



#endif