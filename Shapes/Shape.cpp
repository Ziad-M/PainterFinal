#include "shape.h"
#include "../GUI/GUI.h"

shape::shape()
{}

shape::shape(GfxInfo shapeGfxInfo)
{ 
	ShpGfxInfo = shapeGfxInfo;	//Default status is non-filled.
}
 
void shape::SetSelected(bool s)
{	ShpGfxInfo.isSelected = s; }

bool shape::IsSelected() const
{	return ShpGfxInfo.isSelected; }

void shape::ChngDrawClr(color Dclr)
{	ShpGfxInfo.DrawClr = Dclr; }

void shape::ChngFillClr(color Fclr)
{
	ShpGfxInfo.isFilled = true;
	ShpGfxInfo.FillClr = Fclr;
}
void shape::ChngDrawWidth(int Wnum)
{
	ShpGfxInfo.BorderWdth = Wnum;
}
void shape::setImage()
{
	Image = true;
}
void shape::StickImage(GUI* pGUI)
{
}
bool shape::isImageThere()
{
	return Image;
}

void shape::groupset(int i)
{
	group = i;
}
int shape::groupget()
{
	return group;
}