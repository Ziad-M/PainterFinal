#pragma once
#include "Shape.h"
class polygon : public shape
{
private:
	Point center;
	Point point1;
	int num = 0;
	double distance;
	int* arrayX = new int[num];
	int* arrayY = new int[num];

public:
	polygon(Point, Point, int, GfxInfo shapeGfxInfo);
	virtual ~polygon();
	virtual void Draw(GUI* pUI) const;
	virtual void  save();
	virtual shape* copy();
	virtual shape* Paste(Point);
	virtual bool point_included(int x, int y);
	void OPZOOM(double px, double py, double scale);
	void ResizeShape(double scale);  	//Resize a single ellipse
	void RotateShape();  	//Rotate a single ellipse
	void Scramble(int i, int j);
	void StickImage(GUI* pGUI) override;
};