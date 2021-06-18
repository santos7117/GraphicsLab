#pragma once
#ifndef _MID_POINT_CIRCLE_H
#define _MID_POINT_CIRCLE_H

#include <iostream>
#include <graphics.h>


using std::cout;
using std::cin;

void plot(int xc,int yc,int x,int y)
{
    putpixel( x+xc, y+yc, WHITE);
    putpixel( y+xc, x+yc, WHITE);
    putpixel( y+xc,-x+yc, WHITE);
    putpixel( x+xc,-y+yc, WHITE);
    putpixel(-x+xc,-y+yc, WHITE);
    putpixel(-y+xc,-x+yc, WHITE);
    putpixel(-y+xc, x+yc, WHITE);
    putpixel(-x+xc, y+yc, WHITE);
}

void MidPointCircle()
{    
    char ans;
    int xc,yc,r,p,x,y;

    do {

        cout << "Enter center of the circle :";
        cin >> xc >> yc;
        cout << "Enter radius of the circle :";
        cin >> r;

        x = 0;
        y = r;
        p = 1 - r;

        do {

            plot(xc, yc, x, y);

            // determine next decision parameter
            if (p < 0)
                p = p + 2 * x + 1;
            else {
                y--;
                p = p + 2 * x + 1 - 2 * y;
            }
            x++;

        } while (x < y);

        cout << "Wanna continue? (y/n) ";
        cin >> ans;
    } while (ans == 'y');

}



#endif