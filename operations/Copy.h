#pragma once

#include "operation.h"

class Copy : public operation
{
public:
	Copy(controller*);
	virtual void Execute();
	virtual void Undo() override;
	virtual void Redo() override;
};
