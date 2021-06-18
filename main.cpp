#include "lab1/DDALine.h"
#include "lab2/BresenhamLine.h"
#include "lab3/MidPointCircle.h"
#include "lab4/MidPointEllipse.h"
#include "lab5/FixedPointRotation.h"
#include "lab5/FixedPointScaling.h"


int main()
{
	int gd = graphics_drivers::DETECT, gm, errcode;
	initgraph(&gd, &gm, "");
	errcode = graphresult();
	if (errcode != graph_errors::grOk)	cout << grapherrormsg(errcode);

	//DDALine();
	//BresenhamLine();
	//MidPointCircle();
	//MidPointEllipse();
	//FixedPointRotation();
	//FixedPointScaling();

	closegraph();
}