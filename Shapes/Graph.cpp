#include "Graph.h"
#include "../GUI/GUI.h"
#include"../Shapes/Shape.h"
Graph::Graph()
{
	selectedShape = nullptr;
}

Graph::~Graph()
{
	selectedShape = nullptr;
}

//==================================================================================//
//						shapes Management Functions								//
//==================================================================================//

//Add a shape to the list of shapes
void Graph::Addshape(shape* pShp)
{
	//Add a new shape to the shapes vector
	shapesList.push_back(pShp);	
}

shape* Graph::GetSelected()
{
	return selectedShape;
}
////////////////////////////////////////////////////////////////////////////////////
//Draw all shapes on the user interface
void Graph::Draw(GUI* pUI) const
{
	pUI->ClearDrawArea();
	for (auto shapePointer : shapesList)
		shapePointer->Draw(pUI);
}

void Graph::Save(ofstream& outfile) {
	int sv = shapesList.size();
	outfile << " Shape_ Type  shape_ID  Shape_parameters " << endl; 
	for (int i = 0; i < sv; i++) {
		shapesList[i]->Save(outfile);
	    isSaved = true;
	}

}

shape* Graph::Getshape(int x, int y)
{
	for (auto shapePointer = shapesList.rbegin(); shapePointer != shapesList.rend(); ++shapePointer)
		if ((*shapePointer)->point_included(x, y))
		{
			selectedShape = (*shapePointer);
			return selectedShape;
			break;
		}
		else
		{
			return nullptr;
		}
	return nullptr;
}
void Graph::UnselectShapes()
{
	for (auto shapePointer : shapesList)
		shapePointer->SetSelected(false);
	selectedShape = nullptr;
}

shape* Graph::GetSelectedShape() {
	return selectedShape;
}
shape* Graph::GetSelectedShape() const {
	return selectedShape;
}
void Graph::ZOOM_IN_OUT(double scale, double X, double Y)  //zooming function to determine the point(origin) and the scale factor
{
	for (int k = 0; k < shapesList.size(); k++)  //looping on the list of shapes
	{

		shapesList[k]->OPZOOM(X, Y, scale); //zooming shapes

	}
}

void Graph::RESIZE(double scale)  //loop on the shape list then resize the selected shape
{
	for (int i = 0; i < shapesList.size(); i++) {
		if (selectedShape == shapesList[i]) 
		{
			shapesList[i]->ResizeShape(scale);
		}
	}
}

void Graph::ROTATE() //loop on the shape list then rotate the selected shape
{
	for (int k = 0; k < shapesList.size(); k++) {
		if (selectedShape == shapesList[k]) {
			shapesList[k]->RotateShape();
		}
	}
}
void Graph::Scramble()
{
	int x[4][6] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int temp1, temp2;
	for (int i = 0; i < shapesList.size(); i++)
	{
		/*(200,150) (400, 150) (600, 150) (800, 150) (1000, 150) (1200, 150)
		(200,300) (400, 300) (600, 300) (800, 300) (1000, 300) (1200, 300)
		(200,450) (400, 450) (600, 450) (800, 450) (1000, 450) (1200, 450)
		(200,450) (400, 450) (600, 450) (800, 450) (1000, 450) (1200, 450)*/

		while (true)
		{
			temp1 = rand() % 5;
			temp2 = rand() % 3;
			if (x[temp2][temp1] == 0)
				break;
		}
		x[temp2][temp1] = 1;
			if (i < 5)
			{
				shapesList[i]->Scramble((temp1+1)*200, (temp2 + 1) *150);
			}
			else if (i < 11)
			{
				shapesList[i]->Scramble((temp1 + 1) * 200, (temp2 + 1) * 150);
			}
			else if (i < 17)
			{
				shapesList[i]->Scramble((temp1 + 1) * 200, (temp2 + 1) * 150);
			}
			else if (i < 23)
			{
				shapesList[i]->Scramble((temp1 + 1) * 200, (temp2 + 1) * 150);
			}

	}
}
void Graph::SendFromShapesListToUndo()
{
	if (shapesList[shapesList.size() - 1]) // Excutes if there are 1+
	{
		UndoneShapesList.push_back(shapesList[shapesList.size() - 1]);
		shapesList.erase(shapesList.end() - 1);
		
	}
}

void Graph::SendFromUndoToShapesList()
{
	if (UndoneShapesList[UndoneShapesList.size() - 1])
	{
		shapesList.push_back(UndoneShapesList[UndoneShapesList.size() - 1]);
		UndoneShapesList.erase(UndoneShapesList.end() - 1);
	
	}
}

void Graph::AddGroupNum(int i)
{
	for (int i = 0; i < shapesList.size(); i++)
	{
		if (shapesList[i]->IsSelected())
		{
			shapesList[i]->groupset(i);
		}
	}

}

void Graph::DeleteGroupNum(int i)
{
	for (int i = 0; i < shapesList.size(); i++)
	{
		if (shapesList[i]->groupget() == i)
		{
			shapesList[i]->groupset(0);
		}
	}

}

void Graph::DeleteGroup(int i)
{
	for (int i = 0; i < shapesList.size(); i++)
	{
		if (shapesList[i]->groupget() == i)
		{
			delete [] shapesList[i];
			for (int j = i; j < i; j++)
				shapesList[j] = shapesList[j + 1];
		}
	}
}





//void Graph::StickImage(GUI* pGUI) const
//{
//	for (shape* aShape : shapesList) {
//		if (aShape->(isImageThere))
//		{
//			aShape->StickImage(pGUI);
//		}
//	}
//}
