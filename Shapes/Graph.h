#pragma once
#include "Shape.h"
#include <fstream>
#include <vector>
using namespace std;

//forward decl
class GUI;	

//A class that is responsible on everything related to shapes
class Graph
{
private:
	vector <shape*> UndoneShapes;
	vector <shape*> shapesList; //a container to hold all shapes							   
	shape* selectedShape;	//pointer to the currently selected shape
public:										
	Graph();
	~Graph();
	void Addshape(shape* pFig); //Adds a new shape to the shapesList
	void Draw(GUI* pUI) const;			//Draw the graph (draw all shapes)
	shape* Getshape(int x, int y); //Search for a shape given a point inside the shape
	shape* GetSelected(); //get the selected shape
	void AddToUndoStack();
	void AddtoShapeList();
	shape* GetSelectedShape() const;
	void UnselectShapes();
    void Save(ofstream& outfile);	//Save all shapes to a file
	void Load(ifstream& inputfile);
	shape* GetSelectedShape();
	//Load all shapes from a file
	void ZOOM_IN_OUT(double scale, double X, double Y);  //zooming function
	void RESIZE(double n);              //RESIZE FUNCTION
	void ROTATE();  //rotate a single shape by 90 deg
	void Scramble();
	bool isSaved = false;
};
