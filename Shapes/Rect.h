#pragma once

#include "shape.h"

class Rect : public shape
{
private:
	Point Corner1;	
	Point Corner2;
public:
	Rect();
	Rect(Point , Point, GfxInfo shapeGfxInfo );
	virtual ~Rect();
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
	virtual shape* copy();
	virtual shape* Paste(Point);
	virtual void Draw(GUI* pUI) const;
	virtual bool point_included(int z, int y);
	void OPZOOM(double px, double py, double scale);
	void ResizeShape(double scale);  	//Resize a single rectangle
	void RotateShape();  	//Rotate a single rectangle
	void Scramble();
};

