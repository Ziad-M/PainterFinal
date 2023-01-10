#include "Ctriangle.h"
#include <cmath>

Ctriangle::Ctriangle(Point P1, Point P2, Point P3, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	corner3 = P3;
}
Ctriangle::~Ctriangle() {}
void Ctriangle::Save(ofstream& OutFile)
{
}
void Ctriangle::Load(ifstream& Infile)
{
}
void Ctriangle::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawTriangle(Corner1, Corner2, corner3, ShpGfxInfo);
}

shape* Ctriangle::copy()
{
	shape* ptr = new Ctriangle(Corner1, Corner2, corner3, ShpGfxInfo);
	return ptr;
}

shape* Ctriangle::Paste(Point p)
{
	Ctriangle* triangle = new  Ctriangle(Corner1, Corner2, corner3,  ShpGfxInfo);

	Point oo;
	oo.x = (Corner1.x + Corner2.x) / 2;
	oo.y = (Corner1.y + Corner2.y) / 2;
	triangle->Corner1.x = p.x - oo.x + Corner1.x;
	triangle->Corner1.y = p.y - oo.y + Corner1.y;
	triangle->Corner2.x = p.x - oo.x + Corner2.x;
	triangle->Corner2.y = p.y - oo.y + Corner2.y;
	return triangle;
}
double Ctriangle::triarea(int x1, int x2, int x3, int y1, int y2, int y3) {
	double triangle_area = abs(x1 * (y2 - y3) - y1 * (x2 - x3) + ((x2 * y3) - (y2 * x3))) / 2;
	return triangle_area;
}

bool Ctriangle::point_included(int x, int y) {
	double areaoftriangle = triarea(Corner1.x, Corner2.x, corner3.x, Corner1.y, Corner2.y, corner3.y);
	double area1, area2, area3;
	area1 = triarea(x, Corner2.x, corner3.x, y, Corner1.y, corner3.y);
	area2 = triarea(Corner1.x, x, corner3.x, Corner1.y, y, corner3.y);
	area3 = triarea(Corner1.x, Corner2.x, x, Corner1.y, Corner2.y, y);

	if (areaoftriangle == area1 + area2 + area3)
		return true;

	else
		return false;
}

void Ctriangle::OPZOOM(double px, double py, double scale)  //function to zoom in or out according to the value of the scale factor
{

	Corner1.x = (Corner1.x * scale) - (scale * px) + px;
	Corner1.y = (Corner1.y * scale) - (scale * py) + py;
	Corner2.x = (Corner2.x * scale) - (scale * px) + px;
	Corner2.y = (Corner2.y * scale) - (scale * py) + py;
	corner3.x = (corner3.x * scale) - (scale * px) + px;
	corner3.y = (corner3.y * scale) - (scale * py) + py;

}
void Ctriangle::ResizeShape(double scale)  	//Resize a single triangle
{}
void Ctriangle::RotateShape()  	//Rotate a single triangle
{}

void Ctriangle::Scramble(int i, int j)
{
	/*
	int temp1tri = rand() % 1300;
	int temp2tri = rand() % 650;
	double CenterX = (Corner1.x + Corner2.x + corner3.x) / 3;
	double CenterY = (Corner1.y + Corner2.y + corner3.y) / 3;
	double x = temp1tri - CenterX;
	double y = temp2tri - CenterY;

	Corner1.x = Corner1.x + x;
	Corner1.y = Corner1.y + y;
	Corner2.x = Corner2.x + x;
	Corner2.y = Corner2.y + y;
	corner3.x = corner3.x + x;
	corner3.y = corner3.y + y;
	*/
	double CenterX = (Corner1.x + Corner2.x + corner3.x) / 3;
	double CenterY = (Corner1.y + Corner2.y + corner3.y) / 3;

	Corner1.x = i;
	Corner1.y = j + ((Corner1.y - CenterY) / j) * 50;
	Corner2.x = i + ((Corner2.x - CenterX) / i) * 50;
	Corner2.y = j + ((Corner2.y - CenterY) / j) * 50;
	corner3.x = i + ((corner3.x - CenterX) / i) * 50;
	corner3.y = j + ((corner3.y - CenterY) / j) * 50;

}
void Ctriangle::StickImage(GUI* pGUI)
{
	double MaxPx = max(max(Corner1.x, Corner2.x), corner3.x);
	double MinPx = min(min(Corner1.x, Corner2.x), corner3.x);
	double MaxPy = max(max(Corner1.y, Corner2.y), corner3.y);
	double MinPy = min(min(Corner1.y, Corner2.y), corner3.y);
	Point P;
	P.x = MinPx;
	P.y = MinPy;
	int width = MaxPx - MinPx;
	int length = MaxPy - MinPy;
	string image = "images\\MenuIcons\\Stick.jpg";
	pGUI->StickImage(image, P, width, length);
}
