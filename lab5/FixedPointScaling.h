#pragma once
#ifndef _FIXED_POINT_SCALING_H
#define _FIXED_POINT_SCALING_H

#include <iostream>
#include <graphics.h>
#include <math.h>

using std::cout;
using std::cin;
using std::endl;

typedef unsigned short int index;

void FixedPointScaling()
{
    char ans;
    int xa[10], ya[10], sx, sy, rx, ry, xa1[10], ya1[10];

    do {
        cout << "Enter coordinates of triangle: " << endl;
        
        for (index i{ 0 }; i < 3; i++) {
            cin >> xa[i] >> ya[i];
        }

        // before scaling
        for (index i{ 0 }; i < 3; i++) {
            line(xa[i], ya[i], xa[(i + 1) % 3], ya[(i + 1) % 3]);
        }

        cout << "Enter scaling factor: ";
        cin >> sx >> sy;
        cout << "Enter reference point: ";
        cin >> rx >> ry;

        for (index i{ 0 }; i < 3; i++) {
            xa1[i] = xa[i] * sx + rx * (1 - sx);
            ya1[i] = ya[i] * sy + ry * (1 - sy);
        }

        // after scaling
        for (index i{ 0 }; i < 3; i++) {
            line(xa1[i], ya1[i], xa1[(i + 1) % 3], ya1[(i + 1) % 3]);
        }

        cout << "Wanna continue? (y/n) ";
        cin >> ans;
    } while (ans == 'y');
}



#endif