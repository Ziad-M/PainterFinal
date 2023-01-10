#pragma once
#include "operations/operation.h"
#include "Shapes/Shape.h"
#include "controller.h"
class opStickImage : public operation
{
public:
	opStickImage(controller* pCont);
	~opStickImage();
	virtual void Execute();
	virtual void Undo() override;
	virtual void Redo() override;
};