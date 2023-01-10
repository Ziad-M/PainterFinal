#include "Scramble.h"
#include "..\controller.h"
#include "..\GUI\GUI.h"
#include "..\Shapes/Graph.h"


opScramble::opScramble(controller* pCont) :operation(pCont)
{}

opScramble::~opScramble()
{}

void opScramble::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	pGr->Scramble();
	pUI->PrintMessage("Shapes are Scrambled");
	pUI->ClearStatusBar();
}
void opScramble::Undo()
{
	
}
void opScramble::Redo()
{
	
}