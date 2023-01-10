#include "Copy.h"
#include "../controller.h"
#include"../Shapes/Shape.h"

Copy::Copy(controller* pCont) :operation(pCont)
{
}

void Copy::Execute()
{
	shape* pntr1;
	shape* pntr2;
	GUI* pUI = pControl->GetUI();
	Graph* pGraph = pControl->getGraph();
    pntr1 = pGraph->GetSelected();
	if (pntr1->IsSelected() == true)
	{
		pntr2 = pntr1->copy();
		pControl->SetClipboard(pntr2);
		pUI->PrintMessage("The selected shape has been copied.");
	}
	else
	{
		pUI->PrintMessage("Select a shape first");
	}
}
void Copy::Undo()
{
	Graph* pGr = pControl->getGraph();
	pGr->SendFromShapesListToUndo();
}
void Copy::Redo()
{
	Graph* pGr = pControl->getGraph();
	pGr->SendFromUndoToShapesList();
}