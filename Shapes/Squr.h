#pragma once

#include "shape.h"

class Squr : public shape
{
private:
	Point Corner1;
	Point Corner2;
public:
	Squr();
	Squr(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Squr();
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
	virtual void Draw(GUI* pUI) const;
	virtual shape* copy();
	virtual shape* Paste(Point);
	virtual bool point_included(int x, int y);

	void OPZOOM(double px, double py, double scale);
	void ResizeShape(double scale);  	//Resize a single square
	void RotateShape();  	//Rotate a single square
	void Scramble(int i, int j);
	void StickImage(GUI* pGUI) override;
};