#pragma once
#include "..\defs.h"
#include "..\GUI\GUI.h"


//Base class for all shapes
class shape
{
protected:
	int ID;		//Each shape has an ID
	GfxInfo ShpGfxInfo;	//shape graphis info
	shape* pntr;
	shape* pntrr;
	bool Image = false;
	int group = 0;
	/// Add more parameters if needed.

public:
    shape();
	shape(GfxInfo shapeGfxInfo);
	virtual ~shape() {}
	void SetSelected(bool s);	//select/unselect the shape
	bool IsSelected() const;	//check whether fig is selected

	virtual void Draw(GUI* pUI) const  = 0 ;		//Draw the shape
	
	shape* pshp;
	void ChngDrawClr(color Dclr);	//changes the shape's drawing color
	void ChngFillClr(color Fclr);	//changes the shape's filling color
	void ChngDrawWidth(int Wnum);
	///The following functions should be supported by the shape class
	///It should be overridden by each inherited shape



















































































	///Decide the parameters that you should pass to each function	
	virtual bool point_included(int x, int y) = 0;

	virtual void Save(ofstream &OutFile) = 0;	//Save the shape parameters to the file
	virtual void Load(ifstream &Infile) = 0;	//Load the shape parameters to the file

	virtual shape* copy() = 0;
	virtual shape* Paste(Point) = 0;
	//virtual void PrintInfo(Output* pOut) = 0;	//print all shape info on the status bar
	virtual void OPZOOM(double x, double y, double scale) = 0;   //virtual func. to zoom all shapes
	virtual void ResizeShape(double scale) = 0;  	//Resize a single shape
	virtual void RotateShape() = 0;  	//Rotate a single shape
	virtual void Scramble(int i, int j) = 0;
	virtual void StickImage(GUI* pGUI);
	void groupset(int i);
	int groupget();
	bool isImageThere();
	void setImage();

};

//double Fcaldistance(Point x ,Point y); 
