#include "Cregpolygon.h"
#include <math.h>
#include <corecrt_math_defines.h>



polygon::polygon(Point p1, Point p2, int i, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	center.x = p1.x;
	center.y = p1.y;
	point1.x = p2.x;
	point1.y = p2.y;
	num = i;
	distance = sqrt(pow(point1.x - center.x, 2) + pow((point1.y - center.y), 2));
}
polygon::~polygon()
{}
void polygon::Draw(GUI* pUI) const
{
	if (num == 4) {
		for (int i = 0; i < num; i++)
		{

			int vertixofX = center.x + distance * cos(i * 2 * M_PI / num);
			int vertixofY = center.y + distance * sin(i * 2 * M_PI / num);
			arrayX[i] = vertixofX; arrayY[i] = vertixofY;
		}
		pUI->DrawPolygon(arrayX, arrayY, num, ShpGfxInfo);
	}
	else
	{
		double x = ((num - 2) * M_PI) / (2 * num);
		for (int i = 0; i < num; i++)
		{

			int vertixofX = center.x + distance * cos(i * 2 * M_PI / num + x);
			int vertixofY = center.y + distance * sin(i * 2 * M_PI / num + x);
			arrayX[i] = vertixofX;
			arrayY[i] = vertixofY;
		}pUI->DrawPolygon(arrayX, arrayY, num, ShpGfxInfo);
	}

	double x = ((num - 2) * M_PI) / (2 * num);
	for (int i = 0; i < num; i++)
	{
		int vertixofX = center.x + distance * cos(i * 2 * M_PI / num + x);
		int vertixofY = center.y + distance * sin(i * 2 * M_PI / num + x);
		arrayX[i] = vertixofX;
		arrayY[i] = vertixofY;
	}
	pUI->DrawPolygon(arrayX, arrayY, num, ShpGfxInfo);



}

void polygon::save()
{
}

shape* polygon::copy()  //just to run
{
	shape* ptr=NULL;
	return ptr;
}
shape* polygon::Paste(Point) //just to run
{
	shape* ptr=NULL;
	return ptr;
}
bool polygon::point_included(int x, int y) //just to run
{
	double area = 0;
	int j = num - 1;

	double polyarea = 0.0;
	for (int i = 0; i < num; i++)
	{
		polyarea += (arrayX[j] + arrayX[i]) * (arrayY[j] - arrayY[i]);
		j = i;
	}
	polyarea = abs(polyarea / 2.0);

	for (int i = 0; i < num; i++)
	{
		area = area + abs(0.5 * ((x * arrayY[i]) - (arrayX[i] * y) + (arrayX[i] * arrayY[j]) - (arrayX[j] * arrayY[i]) + (arrayX[j] * y) - (x * arrayY[j])));
		j = i;
	};

	if (polyarea == area)
		return true;
	else return false;
}


void  polygon::OPZOOM(double px, double py, double scale)  //function to zoom in or out according to the value of the scale factor
{
	for (int i = 0; i < num; i++)
	{
		double yy = arrayY[i];
		double xx = arrayX[i];
		double vertix_py = py + (scale * yy) - (scale * py);
		arrayY[i] = vertix_py;
		double vertix_px = px + (scale * xx) - (scale * px);
		arrayX[i] = vertix_px;
	}
}

void polygon::ResizeShape(double scale)  	//Resize a single regular polygon
{}

void polygon::RotateShape()  	//Rotate a single regular polygon
{}

void polygon::Scramble()
{
	int temp1 = (rand() % 1000);
	int temp2 = (rand() % 500);
	center.x = temp1;
	center.y = temp2;
	point1.x = temp1 + distance;
	point1.y = temp2;

}