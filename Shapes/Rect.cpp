#include "Rect.h"

Rect::Rect()
{}

Rect::Rect(Point P1, Point P2, GfxInfo shapeGfxInfo):shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}


Rect::~Rect()
{}

void Rect::Save(ofstream & OutFile)
{
}

void Rect::Load(ifstream& Infile)
{
}


shape* Rect::copy()
{
	shape* ptr = new  Rect(Corner1, Corner2, ShpGfxInfo);
	return ptr;
}

shape* Rect::Paste(Point p)
{
	Rect* rect = new  Rect(Corner1, Corner2, ShpGfxInfo);

	Point oo;
	oo.x = (Corner1.x + Corner2.x) / 2;
	oo.y = (Corner1.y + Corner2.y) / 2;
	rect->Corner1.x = p.x - oo.x + Corner1.x;
	rect->Corner1.y = p.y - oo.y + Corner1.y;
	rect->Corner2.x = p.x - oo.x + Corner2.x;
	rect->Corner2.y = p.y - oo.y + Corner2.y;
	return rect;
}


void Rect::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawRect(Corner1, Corner2, ShpGfxInfo);
}
bool Rect::point_included(int x, int y) {

	if ((Corner1.x < Corner2.x && Corner1.y < Corner2.y) && (x > Corner1.x && x<Corner2.x && y>Corner1.y && y < Corner2.y)) {
		return true;
	}
	else if ((Corner1.x < Corner2.x && Corner1.y > Corner2.y) && (x > Corner1.x && x<Corner2.x && y>Corner2.y && y < Corner1.y)) {
		return true;
	}
	else if ((Corner1.x > Corner2.x && Corner1.y < Corner2.y) && (x > Corner2.x && x<Corner1.x && y>Corner1.y && y < Corner2.y))
		return true;
	else if ((Corner1.x > Corner2.x && Corner1.y > Corner2.y) && (x > Corner2.x && x<Corner1.x && y>Corner2.y && y < Corner1.y))
		return true;
	else
		return false;
}
void  Rect::OPZOOM(double px, double py, double scale)   //function to zoom in or out according to the value of the scale factor
{
	Corner1.x = (Corner1.x * scale) - (scale * px) + px;
	Corner2.x = (Corner2.x * scale) - (scale * px) + px;
	Corner1.y = (Corner1.y * scale) - (scale * py) + py;
	Corner2.y = (Corner2.y * scale) - (scale * py) + py;
}
void Rect::ResizeShape(double scale)  	//Resize a single rectangle
{}
void Rect::RotateShape()  	//Rotate a single rectangle
{}

void Rect::Scramble()
{
	int temp1 = (rand() % 1000);
	int temp2 = (rand() % 500);
	double CenterX = (Corner1.x + Corner2.x) / 2;
	double CenterY = (Corner1.y + Corner2.y) / 2;
	double dx = temp1 - CenterX;
	double dy = temp2 - CenterY;
	int Temp1x = Corner1.x;
	int Temp1y = Corner1.y;
	int Temp2x = Corner2.x;
	int Temp2y = Corner2.y;

	Corner1.x = Temp1x + dx;
	Corner1.y = Temp1y + dy;
	Corner2.x = Temp2x + dx;
	Corner2.y = Temp2y + dy;

}