#include "Ccircle.h"



Ccircle::Ccircle(Point P1, Point P2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	center = P1;
	border = P2;
}

Ccircle::~Ccircle()
{}

void Ccircle::Save(ofstream & OutFile)
{
}

void Ccircle::Load(ifstream& Infile)
{
}

void Ccircle::Draw(GUI* pUI) const
{
	double rad = sqrt((center.x - border.x) * (center.x - border.x) + (center.y - border.y) * (center.y - border.y));
	//Call Output::Drawcircle to draw a Circle on the screen	
	pUI->DrawCircle(center,rad , ShpGfxInfo);
}

bool Ccircle::point_included(int x, int y) {

	double radius = sqrt(pow(center.x - border.x, 2) + pow(center.y - border.y, 2));
	double d = sqrt(pow(x - center.x, 2) + pow(y - center.y, 2));	 //distance formula for the circle
	if (d <= radius)
		return true;
	else
		return false;
}

shape* Ccircle::copy()  //just to run
{
	shape* ptr=nullptr;
	return ptr = nullptr;
}
shape* Ccircle::Paste(Point) //just to run
{
	shape* ptr;
	return ptr;
}

void  Ccircle::OPZOOM(double px, double py, double scale)  //function to zoom in or out according to the value of the scale factor
{
	Corner1.x = (Corner1.x * scale) - (scale * px) + px;
	Corner1.y = (Corner1.y * scale) - (scale * py) + py;
	Corner2.x = (Corner2.x * scale) - (scale * px) + px;
	Corner2.y = (Corner2.y * scale) - (scale * py) + py;
}

void Ccircle::ResizeShape(double scale)  	//Resize a single regular polygon
{}

void Ccircle::RotateShape()  	//Rotate a single regular polygon
{}

void Ccircle::Scramble(int i, int j)
{
	
	center.x = i;
	center.y = j;

	border.x = i + 50;
	border.y = j;
	



}
void Ccircle::StickImage(GUI* pGUI)
{
	double rad = sqrt(pow((border.x - center.x), 2) + pow((border.y - center.y), 2));
	Point P;
	P.x = center.x - rad;
	P.y = center.y - rad;
	int width = rad * 2;
	int length = width;
	string image = "images\\MenuIcons\\Stick.jpg";
	pGUI->StickImage(image, P, width, length);
}
