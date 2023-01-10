#include "opdelete.h"


opdelete::opdelete(controller* pCont) : operation(pCont)
{
	GUI* pUI = pControl->GetUI();

	Graph* pGr = pControl->getGraph();

//	pGr->Fdelete(pGr->getselected()); 


}



	void opdelete::Execute()
	{}
	void opdelete::Undo()
	{
		Graph* pGr = pControl->getGraph();
		pGr->SendFromShapesListToUndo();
	}
	void opdelete::Redo()
	{
		Graph* pGr = pControl->getGraph();
		pGr->SendFromUndoToShapesList();
	}