#include "Rotate.h"
#include "..\controller.h"

opRotate::opRotate(controller* pCont) :operation(pCont)
{}
opRotate::~opRotate()
{}

//Execute the operation
void opRotate::Execute()
{
	pControl->getGraph()->ROTATE();

}
void opRotate::Undo()
{
	
}
void opRotate::Redo()
{
	
}