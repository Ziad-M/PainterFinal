#pragma once
#include "operation.h"
#include"../CMUgraphicsLib/CMUgraphics.h"

//zoom in class
class opZoomIn : public operation
{
public:
	opZoomIn(controller* pCont);
	virtual ~opZoomIn();

	virtual void Execute();
	virtual void Undo() override;
	virtual void Redo() override;

};

