#pragma once

#include "shape.h"

class Line : public shape
{
private:
	Point Corner1;
	Point Corner2;
public:
	Line();
	Line(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Line();
	virtual bool point_included(int x, int y);
	virtual shape* copy();
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
	virtual void Draw(GUI* pUI) const;
	virtual shape* Paste(Point);
	void OPZOOM(double px, double py, double scale);
	void ResizeShape(double scale);  	//Resize a single line
	void RotateShape();  	//Rotate a single line
	void Scramble(int i, int j);		//Scramble 
	void StickImage(GUI* pGUI) override;
};
