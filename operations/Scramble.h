#pragma once
#include "operation.h"

class opScramble : public operation
{

public:
	opScramble(controller* pCont);
	virtual ~opScramble();
	virtual void Execute();
	virtual void Undo() override;
	virtual void Redo() override;
};
