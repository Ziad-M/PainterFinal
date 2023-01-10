#include "opmultiselect.h"
#include "controller.h"
#include "GUI/GUI.h"
MULTISELECT::MULTISELECT(controller* pApp, int& _multiSelect) : operation(pApp)
{
	this->multiSelect = &_multiSelect;
};


void MULTISELECT::Execute() {
	GUI* pGUI = pControl->GetUI();

	if (*multiSelect)
	{
		*multiSelect = 0;
			pGUI->PrintMessage("MULTISELECT IS STARTED ...");}
	
	else
	{
		*multiSelect = 1;
		pGUI->PrintMessage("MULTISELECT IS STOPED !!");
	}
}
void MULTISELECT::Undo()
{
	Graph* pGr = pControl->getGraph();
	pGr->AddToUndoStack(); 
}
void MULTISELECT::Redo()
{
	Graph* pGr = pControl->getGraph();
	pGr->AddtoShapeList();
}