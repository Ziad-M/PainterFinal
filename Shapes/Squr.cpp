#include "Squr.h"
#include<fstream>
#include "../GUI/GUI.h"
Squr::Squr()
{
}
Squr::Squr(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	double L;
	L = sqrt(pow((P2.x - P1.x), 2) + pow((P2.y - P1.y), 2));
	P2.x = P1.x + L / sqrt(2);
	P2.y = P1.y + L / sqrt(2);
	Corner1 = P1;
	Corner2 = P2;
}

Squr::~Squr()
{}

void Squr::Save(ofstream& outFile)
{
	string DrawColor;
	outFile << " SQUARE " << "	" << ID 
		<< " " << Corner1.x << " " << Corner1.y << " " << Corner2.x << " " << Corner2.y << " " << DrawColor << endl;
}

shape* Squr::Paste(Point p)
{
	Squr*squr = new  Squr(Corner1, Corner2, ShpGfxInfo);

	Point oo;
	oo.x = (Corner1.x + Corner2.x) / 2;
	oo.y = (Corner1.y + Corner2.y) / 2;
	squr->Corner1.x = p.x - oo.x + Corner1.x;
	squr->Corner1.y = p.y - oo.y + Corner1.y;
	squr->Corner2.x = p.x - oo.x + Corner2.x;
	squr->Corner2.y = p.y - oo.y + Corner2.y;
	return squr;
}

void Squr::Load(ifstream& Infile)
{
	string DrawColor;
	Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> DrawColor;
	GfxInfo info;
	Infile >> info.BorderWdth;
	Infile >> info.isFilled;
	Infile >> info.isSelected;
	Infile >> info.FillClr.ucBlue;
	Infile >> info.FillClr.ucGreen;
	Infile >> info.FillClr.ucRed;
	Infile >> info.DrawClr.ucBlue;
	Infile >> info.DrawClr.ucGreen;
	Infile >> info.DrawClr.ucRed;
}

void Squr::Draw(GUI* pUI) const
{
	//Call Output::DrawSqur to draw a square on the screen	
	pUI->DrawSqur(Corner1, Corner2, ShpGfxInfo);
}

shape* Squr::copy()
{
	shape* ptr = new Squr(Corner1, Corner2, ShpGfxInfo);
	return ptr;
}

bool Squr::point_included(int x, int y) {
	double length;
	length = sqrt(pow(Corner2.x - Corner1.x, 2) + pow(Corner2.y - Corner1.y, 2));
	if (x > Corner1.x && x<Corner1.x + length && y>Corner1.y && y < Corner1.y + length)
		return true;

	else
		return false;
}
void Squr::OPZOOM(double px, double py, double scale)  //function to zoom in or out according to the value of the scale factor
{
	Corner1.x = (Corner1.x * scale) - (scale * px) + px;
	Corner2.x = (Corner2.x * scale) - (scale * px) + px;
	Corner1.y = (Corner1.y * scale) - (scale * py) + py;
	Corner2.y = (Corner2.y * scale) - (scale * py) + py;
}
void Squr::ResizeShape(double scale)  	//Resize a single squre
{} 
void Squr::RotateShape()  	//Rotate a single squre
{}

void Squr::Scramble(int i, int j)
{

	/* int temp1 = (rand() % 1000);
	int temp2 = (rand() % 500);

	double CenteroidX = (Corner1.x + Corner2.x) / 2;
	double CenteroidY = (Corner1.y + Corner2.y) / 2;

	double dx = temp1 - CenteroidX;
	double dy = temp2 - CenteroidX;

	int Temp1x = Corner1.x;
	int Temp1y = Corner1.y;
	int Temp2x = Corner2.x;
	int Temp2y = Corner2.y;
	*/
	
	Corner1.x = i - 50;
	Corner1.y = j - 50;
	Corner2.x = i + 50;
	Corner2.y = j + 50;
}
void Squr::StickImage(GUI* pGUI)
{
	Point P;
	P.x = Corner1.x;
	P.y = Corner1.y;
	int width = abs(Corner1.x - Corner2.x);
	int length = abs(Corner1.y - Corner2.y);
	string image = "images\\MenuIcons\\Stick.jpg";
	pGUI->StickImage(image, P, width, length);
}