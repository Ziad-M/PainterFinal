#pragma once
#include "shape.h"
class Ccircle : public shape
{private:
	Point center;
	Point border;
	Point Corner1;
	Point Corner2;
	

public:

	Ccircle(Point, Point, GfxInfo shapeGfxInfo);
	
	
	virtual ~Ccircle();
	virtual bool point_included(int x, int y);
	void Save(ofstream& OutFile);
	void Load(ifstream& Infile);
	virtual void Draw(GUI* pUI) const;
	virtual shape* copy();
	virtual shape* Paste(Point);
	void OPZOOM(double px, double py, double scale);
	void ResizeShape(double scale);  	//Resize a single circle
	void RotateShape();  	//Rotate a single circle
	void Scramble(int i, int j);
	double radprem;
	void StickImage(GUI* pGUI) override;
};

