#pragma once

#include "shape.h"

class Ellip : public shape
{
private:
	Point Corner1;
	Point Corner2;
public:
	Ellip();
	Ellip (Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Ellip();
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
	virtual shape* copy();
	virtual bool point_included(int x, int y);
	virtual void Draw(GUI* pUI) const;
	virtual shape* Paste(Point);
	void OPZOOM(double px, double py, double scale);
	void ResizeShape(double scale);  	//Resize a single ellipse
	void RotateShape();  	//Rotate a single ellipse
	void Scramble(int i, int j);
	void StickImage(GUI* pGUI) override;
};