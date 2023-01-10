#include "controller.h"
#include "operations/opAddRect.h"
#include "operations/opAddtriangle.h"
#include "operations/opAddcircle.h"
#include "operations/opAddregpolygon.h"
#include "operations/opAddIrrPoly.h"
#include "operations/opAddSqur.h"
#include "operations/opAddLine.h"
#include "operations/opAddEllip.h"
#include "operations/SwitchToDraw.h"
#include "operations/SwitchToPlay.h"
#include"operations/opchangeshape.h"
#include "opSelect.h"
//#include "operations\Load.h"
#include"operations/ZoomIn.h"
#include"operations/ZoomOut.h"
#include "operations/Exit.h"
#include"operations/Group.h"
#include"operations/Ungroup.h"
#include"operations/Rotate.h"
#include "operations\opsave.h"
#include "operations/Copy.h"
#include "operations/Paste.h"
#include "operations/Resize.h"
#include "opmultiselect.h" 
#include "opmovebydrag.h"
#include "operations/Scramble.h"
#include "opUndo.h"
#include "opRedo.h"
//Constructor
controller::controller()
{
	pGraph = new Graph;
	pGUI = new GUI;	//Create GUI object
}

//==================================================================================//
//								operations-Related Functions							//
//==================================================================================//
operationType controller::GetUseroperation() const
{
	//Ask the input to get the operation from the user.
	return pGUI->GetUseroperation();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an operation and executes it
operation* controller::createOperation(operationType OpType)
{
	operation* pOp = nullptr;
	
	//According to operation Type, create the corresponding operation object
	switch (OpType)
	{
		case DRAW_RECT:
			pOp = new opAddRect(this);
			newOp(pOp);
			break;

		case DRAW_TRI:
			pOp = new opAddTriangle(this);
			newOp(pOp);
			break;

		case DRAW_CIRC:
			pOp = new opAddCircle(this);
			newOp(pOp);
			break;
		
		case DRAW_RPOLY:
			pOp = new opAddREGPolygon(this); 
			newOp(pOp);
			break;

		case DRAW_LINE:
			pOp = new opAddLine(this);
			newOp(pOp);
			break;

		case DRAW_SQUR:
			pOp = new opAddSqur(this);
			newOp(pOp);
			break;

		case DRAW_ELLIP:
			pOp = new opAddEllip(this);
			newOp(pOp);
			break;

		case DRAW_IRREGPOLY:
			pOp = new opAdd_IIR_POLYGON(this);
			newOp(pOp);
			break;

		case TO_DRAW:
			pOp = new SwitchToDraw(this);
			newOp(pOp);
			break;

		case TO_PLAY:
			pOp = new SwitchToPlay(this);
			newOp(pOp);
			break;

		case COLOR_PALETTE:   //color palette icon 
			pOp = new opClrPlt(this);
			newOp(pOp);
			break;

		case PEN_WIDTH:               //pen width icon
			pOp = new opPenWidth(this);
			newOp(pOp);
			break;
		case SELECT:
			pOp = new opSelect(this);
			newOp(pOp);
			break;

		case ROTATE:   //rotate a shape
			pOp = new opRotate(this);
			newOp(pOp);
			break;

		case ZOOM_IN:   //zoom in
			pOp = new opZoomIn(this);
			newOp(pOp);
			break;

		case ZOOM_OUT:   //zoom out
			pOp = new opZoomOut(this);
			newOp(pOp);
			break;

		case RESIZE:   //resize
			pOp = new opResize(this);
			newOp(pOp);
			break;

		case GROUP:   //group
			pOp = new opGroup(this);
			break;

		case UNGROUP:   //ungroup
			pOp = new opUngroup(this);
			newOp(pOp);
			break;

		case SelctedInfo:   //change selected info 
			pOp = new opChngSelInfo(this);
			newOp(pOp);
			break;

		//case MOVE : 
		//	pOp = new MoveByDrag(this); // move by drag 

		//case LOAD:
		//	pOp = new Load(this);
		//	break;

		case SAVE:
			pOp = new opsave(this);
			newOp(pOp);
			break;

		case COPY:
			pOp = new Copy(this);
			newOp(pOp);
			break;

		case PASTE:
			pOp = new Paste(this);
			newOp(pOp);
			break;
		case UNDO:
			pOp = new opUndo(this);
			break;

		case REDO:
			pOp = new opRedo(this);
			break;

		case MULTISELECTION : 
			pOp = new MULTISELECT(this, multiSelect);
			newOp(pOp);
			break; 

		case EXIT:
			pOp = new Exit(this);
			newOp(pOp);
			break;
		case SCRAMBLE:
			pOp = new opScramble(this);
			newOp(pOp);
			break;
		
		case STATUS:	//a click on the status bar ==> no operation
			break;
	}

	return pOp;
	
}


void controller::SetClipboard(shape* clip) //To store the shape coppied in the clipboard
{
		Clipboard = clip;
}

shape* controller::GetClipboard()const
{
	return Clipboard;
}




//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all shapes on the user interface
void controller::UpdateInterface() const
{	
	pGraph->Draw(pGUI);
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the UI
GUI *controller::GetUI() const
{	return pGUI; }
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the Graph
Graph* controller::getGraph() const
{
	return pGraph;
}



//Destructor
controller::~controller()
{
	delete pGUI;
	delete pGraph;
	
}



//==================================================================================//
//							Run function											//
//==================================================================================//
void controller::Run()
{
	operationType OpType;
	do
	{
		/////////pWind->GetWindowSize(5, 5);
		//1. Ask the GUI to read the required operation from the user
		OpType = GetUseroperation();

		//2. Create an operation coresspondingly
		operation* pOpr = createOperation(OpType);
		//3. Execute the created operation
		if (pOpr)
		{
			pOpr->Execute();//Execute
			//delete pOpr;	//operation is not needed any more ==> delete it
			//pOpr = nullptr;
		}

		//Update the interface
		UpdateInterface();
	} while (OpType != EXIT);

}


operation* controller::PreviousDone() {
	if (DoneStack.empty())
	{
		return nullptr;
		// No Actions in the Done Stack
	}
	else
	{
		return  DoneStack.top();
	}
}


operation* controller::PreviousUndone()
{
	if (!UndoneStack.empty())
	{
		return UndoneStack.top();
	}
	else 
	{
		return nullptr;
		// No operations in the undone stack
	}
}


void controller::newOp(operation* newOperation)
{
	if (newOperation)
	{
		DoneStack.push(newOperation);
	}
}


void controller::Undo()
{
	if (PreviousDone())
	{
		UndoneStack.push(PreviousDone());
		DoneStack.pop();
	}

}

void controller::Redo()
{
	if (PreviousUndone())
	{
		DoneStack.push(PreviousUndone());
		UndoneStack.pop();
	}
}