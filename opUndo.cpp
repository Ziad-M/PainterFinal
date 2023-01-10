#include"opUndo.h"

#include "controller.h"

#include "GUI/GUI.h"

opUndo::opUndo(controller* pCont) :operation(pCont) {}

opUndo::~opUndo() {}

void opUndo::Execute() {
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();

	if (pControl->getLastDoneOp())
	{
		pControl->getLastDoneOp()->Undo();
		pControl->Undo();
		pGr->isSaved = false;
	}
	else {
		pUI->PrintMessage("There is nothing to be Undone!");
	}
}

void opUndo::Undo() {}
void opUndo::Redo() {}