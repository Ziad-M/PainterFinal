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
#include "opStickImage.h"
#include "opUndo.h"
#include "opRedo.h"
#include "DeleteGroup.h"
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
			break;

		case DRAW_TRI:
			pOp = new opAddTriangle(this);
			break;

		case DRAW_CIRC:
			pOp = new opAddCircle(this);
			break;
		
		case DRAW_RPOLY:
			pOp = new opAddREGPolygon(this); 
			break;

		case DRAW_LINE:
			pOp = new opAddLine(this);
			break;

		case DRAW_SQUR:
			pOp = new opAddSqur(this);
			break;

		case DRAW_ELLIP:
			pOp = new opAddEllip(this);
			break;

		case DRAW_IRREGPOLY:
			pOp = new opAdd_IIR_POLYGON(this);
			break;

		case TO_DRAW:
			pOp = new SwitchToDraw(this);
			break;

		case TO_PLAY:
			pOp = new SwitchToPlay(this);
			break;

		case COLOR_PALETTE:   //color palette icon 
			pOp = new opClrPlt(this);
			break;

		case PEN_WIDTH:               //pen width icon
			pOp = new opPenWidth(this);
			break;
		case SELECT:
			pOp = new opSelect(this);
			break;
		case ROTATE:   //rotate a shape
			pOp = new opRotate(this);
			break;

		case ZOOM_IN:   //zoom in
			pOp = new opZoomIn(this);
			break;

		case ZOOM_OUT:   //zoom out
			pOp = new opZoomOut(this);
			break;

		case RESIZE:   //resize
			pOp = new opResize(this);
			break;

		case GROUP:   //group
			pOp = new opGroup(this);
			break;

		case UNGROUP:   //ungroup
			pOp = new opUngroup(this);
			break;


		case STICK:   //change selected info 
			pOp = new opStickImage(this);
			break;

		//case MOVE : 
		//	pOp = new MoveByDrag(this); // move by drag 

		//case LOAD:
		//	pOp = new Load(this);
		//	break;

		case SAVE:
			pOp = new opsave(this);
			break;

		case COPY:
			pOp = new Copy(this);
			break;

		case PASTE:
			pOp = new Paste(this);
			break;

		case MULTISELECTION : 
			pOp = new MULTISELECT(this, multiSelect);
			break; 

		case EXIT:
			pOp = new Exit(this);
			break;
		case SCRAMBLE:
			pOp = new opScramble(this);
			break;
		case UNDO:
			pOp = new opUndo(this);
			break;
		case REDO:
			pOp = new opRedo(this);
			break;
		case STATUS:	//a click on the status bar ==> no operation
			break;
		case DELETE_GROUP:
			pOp = new DeleteGroup(this);
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
// Function to get the last operation added to the stack
operation* controller::getLastDoneOp() {
	if (!Operations.empty()) // if the stack is empty it returns a null pointer 
	{
		return Operations.top();
	}
	else  // otherwise it returns the top of the stack (last action)
	{
		return nullptr;
		pGUI->PrintMessage("There are no actions to be undone!");
	}
}

// Function to get the last undone operation added to the stack
operation* controller::getLastUndoneOp()
{
	if (!UndoneOperations.empty())  // if the stack is empty it returns a null pointer 
	{
		return UndoneOperations.top();
	}
	else  // otherwise it returns the top of the stack (last undone action)
	{
		return nullptr;
		pGUI->PrintMessage("There are no actions to be redone!");
	}
}

// Function to add a new operation to the stack
void controller::addNewOp(operation* newOperation)
{
	if (newOperation)
	{
		Operations.emplace(newOperation);
	}
}

// Function to Undo last made action
void controller::Undo()
{
	if (getLastDoneOp())
	{
		UndoneOperations.emplace(getLastDoneOp());
		Operations.pop();
	}

}

// Function to Redo last made action
void controller::Redo()
{
	if (getLastDoneOp())
	{
		Operations.emplace(getLastUndoneOp());
		UndoneOperations.pop();
	}
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
			delete pOpr;	//operation is not needed any more ==> delete it
			pOpr = nullptr;
		}

		//Update the interface
		UpdateInterface();

	} while (OpType != EXIT);

}


