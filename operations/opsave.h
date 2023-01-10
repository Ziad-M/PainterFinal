#pragma once
#include "..\Shapes/Graph.h"
#include "..\operations/operation.h"
#include "..\GUI/GUI.h " 
#include <fstream>
class opsave :public operation
{
public:
	opsave(controller* pCont) :operation(pCont) {}
	virtual ~opsave();
	virtual void Execute();
	virtual void Undo() override;
	virtual void Redo() override;
};
