#include "Ellip.h"
#include<fstream>
Ellip::Ellip()
{

}

Ellip::Ellip(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}

Ellip::~Ellip()
{}

void Ellip::Save(ofstream& outFile)
{
	string DrawColor;
	outFile << ID << Corner1.x << Corner1.y << Corner2.x << Corner2.y << DrawColor;
	GfxInfo info;
	outFile << info.BorderWdth;
	outFile << info.isFilled;
	outFile << info.isSelected;
	outFile << info.FillClr.ucBlue;
	outFile << info.FillClr.ucGreen;
	outFile << info.FillClr.ucRed;
	outFile << info.DrawClr.ucBlue;
	outFile << info.DrawClr.ucGreen;
	outFile << info.DrawClr.ucRed;
}


void Ellip::Load(ifstream& Infile)
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

void Ellip::Draw(GUI* pUI) const
{
	//Call Output::DrawEllip to draw an ellipse on the screen	
	pUI->DrawEllip(Corner1, Corner2, ShpGfxInfo);
}

shape* Ellip::copy()
{
	shape* ptr = new  Ellip(Corner1, Corner2, ShpGfxInfo);
	return ptr;
}

shape* Ellip::Paste(Point p)
{
	Ellip* ellip = new  Ellip(Corner1, Corner2, ShpGfxInfo);

	Point oo;
	oo.x = (Corner1.x + Corner2.x) / 2;
	oo.y = (Corner1.y + Corner2.y) / 2;
	ellip->Corner1.x = p.x - oo.x + Corner1.x;
	ellip->Corner1.y = p.y - oo.y + Corner1.y;
	ellip->Corner2.x = p.x - oo.x + Corner2.x;
	ellip->Corner2.y = p.y - oo.y + Corner2.y;
	return ellip;
}
bool Ellip::point_included(int x, int y)
{
	return true;
}
void  Ellip::OPZOOM(double px, double py, double scale)  //function to zoom in or out according to the value of the scale factor
{
	Corner1.x = (Corner1.x * scale) - (scale * px) + px;
	Corner1.y = (Corner1.y * scale) - (scale * py) + py;
	Corner2.x = (Corner2.x * scale) - (scale * px) + px;
	Corner2.y = (Corner2.y * scale) - (scale * py) + py;
}
void Ellip::ResizeShape(double scale)  	//Resize a single ellipse
{}

void Ellip::RotateShape()  	//Rotate a single ellipse
{}


void Ellip::Scramble(int i, int j)
{ /*
p1 = (rand() % 1000);
	int temp2 = (rand() % 500);
	Point oo;
	oo.x = (Corner1.x + Corner2.x) / 2;
	oo.y = (Corner1.y + Corner2.y) / 2;
	Corner1.x = temp1 - oo.x + Corner1.x;
	Corner1.y = temp2 - oo.y + Corner1.y;
	Corner2.x = temp1 - oo.x + Corner2.x;
	Corner2.y = temp2 - oo.y + Corner2.y;
	*/
	Corner1.x = i -80;
	Corner1.y = j -40;
	Corner2.x = i +80;
	Corner2.y = j +40;
}
void Ellip::StickImage(GUI* pGUI)
{
	
}
