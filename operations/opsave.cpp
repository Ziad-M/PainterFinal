#include "opsave.h"
#include "..\controller.h"
#include "..\GUI/GUI.h"
opsave::~opsave(){}
void opsave::Execute()
{
	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage("ENTER FILE NAME ..");
	string name = pUI->GetSrting();
	ofstream outfile(name);
	pControl->getGraph()->Save(outfile);
	pUI->PrintMessage("saved succesfully "); 

}
void opsave::Undo()
{
	Graph* pGr = pControl->getGraph();
	pGr->SendFromShapesListToUndo();
}
void opsave::Redo()
{
	Graph* pGr = pControl->getGraph();
	pGr->SendFromUndoToShapesList();
}