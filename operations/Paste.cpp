#include "Paste.h"
#include "../controller.h"
#include "../GUI/GUI.h"

Paste::Paste(controller* pCont) :operation(pCont)
{}


void Paste::Execute()
{


	if (pControl->GetClipboard())
	{

		GUI* pUI = pControl->GetUI();

		pUI->PrintMessage("Click on the Drawing Area to paste");

		pUI->GetPointClicked(p1.x, p1.y);

		pUI->ClearStatusBar();

		shape* pntr1, * pntr2;

		pntr1 = pControl->GetClipboard();

		pntr2 = pntr1-> Paste(p1);

        //shape should be added by a function
		//To be completed

	}

	else
	{
		GUI* pUI = pControl->GetUI();
		pUI->PrintMessage("copy or cut a shape first");
	}
}
void Paste::Undo()
{
	Graph* pGr = pControl->getGraph();
	pGr->SendFromShapesListToUndo();
}
void Paste::Redo()
{
	Graph* pGr = pControl->getGraph();
	pGr->SendFromUndoToShapesList();
}