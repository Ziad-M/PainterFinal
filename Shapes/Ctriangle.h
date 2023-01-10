#pragma once

#include "shape.h"

class Ctriangle : public shape
{
private:
	Point Corner1;
	Point Corner2;
	Point corner3;
public:
	Ctriangle(Point, Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Ctriangle();
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
	virtual shape* copy();
	virtual void Draw(GUI* pUI) const;
	double triarea(int, int, int, int, int, int);
	virtual bool point_included(int x, int y);
	virtual shape* Paste(Point);
	void OPZOOM(double px, double py, double scale);
	void ResizeShape(double scale);  	//Resize a single triangle
	void RotateShape();  	//rotate a single triangle
	void Scramble(int i, int j);
	void StickImage(GUI* pGUI) override;
};

