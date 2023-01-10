#include "Ungroup.h"
#include "..\controller.h"
#include "../CMUgraphicsLib/CMUgraphics.h"

opUngroup::opUngroup(controller* pCont) :operation(pCont)
{}
opUngroup::~opUngroup()
{}

//Execute the operation
void opUngroup::Execute()
{



}
void opUngroup::Undo()
{
	Graph* pGr = pControl->getGraph();
	pGr->AddToUndoStack();
}
void opUngroup::Redo()
{
	Graph* pGr = pControl->getGraph();
	pGr->AddtoShapeList();
}