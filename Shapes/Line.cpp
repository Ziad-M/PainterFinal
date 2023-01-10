#include "Line.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;
Line::Line()
{

}
Line::Line(Point P1, Point P2, GfxInfo shapeGfxInfo):shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}

Line::~Line()
{}

void Line::Save(ofstream& outFile)
{
	string DrawColor;
	outFile << ID << Corner1.x << Corner1.y << Corner2.x << Corner2.y << DrawColor;
	GfxInfo info;
	outFile << info.isSelected;
	outFile << info.DrawClr.ucBlue;
	outFile << info.DrawClr.ucGreen;
	outFile << info.DrawClr.ucRed;
}

void Line::Load(ifstream& Infile)
{
	string DrawColor;
	Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> DrawColor;
	GfxInfo info;
	Infile >> info.isSelected;
	Infile >> info.DrawClr.ucBlue;
	Infile >> info.DrawClr.ucGreen;
	Infile >> info.DrawClr.ucRed;
}

void Line::Draw(GUI* pUI) const
{
	//Call Output::DrawLine to draw a line on the screen	
	pUI->DrawLn(Corner1, Corner2, ShpGfxInfo);

}

shape* Line::copy()
{
	shape* ptr = new Line (Corner1, Corner2, ShpGfxInfo);
	return ptr;
}



shape* Line::Paste(Point p)
{
	Line* line = new  Line(Corner1, Corner2, ShpGfxInfo);

	Point oo;
	oo.x = (Corner1.x + Corner2.x) / 2;
	oo.y = (Corner1.y + Corner2.y) / 2;
	line->Corner1.x = p.x - oo.x + Corner1.x;
	line->Corner1.y = p.y - oo.y + Corner1.y;
	line->Corner2.x = p.x - oo.x + Corner2.x;
	line->Corner2.y = p.y - oo.y + Corner2.y;
	return line;
}

bool Line::point_included(int x, int y) {
	double slope = (Corner2.y - Corner1.y) / (Corner2.x - Corner1.x);
	double nslope = (y - Corner1.y) / (x - Corner2.x);
	if (nslope == slope || nslope == -slope) {
		return true;
	}
	else { return false; }
}

void  Line::OPZOOM(double px, double py, double scale)  //function to zoom in or out according to the value of the scale factor
{
	Corner1.x = (Corner1.x * scale) - (scale * px) + px;
	Corner1.y = (Corner1.y * scale) - (scale * py) + py;
	Corner2.x = (Corner2.x * scale) - (scale * px) + px;
	Corner2.y = (Corner2.y * scale) - (scale * py) + py;
}
void Line::ResizeShape(double scale)  	//Resize a single line
{}
void Line::RotateShape()  	//Rotate a single line
{}

void Line::Scramble(int i, int j)
{
	/*int temp1 = (rand() % 1000);
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
	Corner2.y = Temp2y + dy;*/
	/*int x = rand()% 1300;
	int y = rand()% 700;

	double corner1tempx = Corner1.x;
	double corner1tempy = Corner1.y;
	double corner2tempx = Corner2.x;
	double corner2tempy = Corner2.y;

	Corner1.x = corner1tempx + x - (corner1tempx + corner2tempx) / 2;
	Corner1.y = corner1tempy + y - (corner1tempy + corner2tempy) / 2;
	Corner2.x = corner2tempx + x - (corner1tempx + corner2tempx) / 2;
	Corner2.y = corner2tempy + y - (corner1tempy + corner2tempy) / 2;
	/*
	if(Corner1.y < 50 ) 
	Corner1.y + 50; Corner2.y + 50;
	if(Corner2.y < 50 ) 
	Corner2.y + 50; Corner1.y + 50;
	if(Corner1.y > 650 ) 
	Corner1.y - 50; Corner2.y - 50;
	if(Corner2.y > 650 ) 
	Corner1.y - 50; Corner2.y - 50;*/
	Corner1.x = i;
	Corner1.y = j;
	Corner2.x = i + 100;
	Corner2.y = j;

}
void Line::StickImage(GUI* pGUI)
{
}
