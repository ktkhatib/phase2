
#include "AddTriangleAction.h"
#include "CTriangle.h"
#include "ApplicationManager.h"
#include "GUI/Input.h"
#include "GUI/Output.h"
#include "Actions/Action.h"
AddTriangleAction::AddTriangleAction(ApplicationManager* pApp) :Action(pApp)
{
}

void AddTriangleAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at first corner ");

	//Read the center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);
	pOut->PrintMessage("New Triangle: Click at second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);
	pOut->PrintMessage("New Triangle: Click at third corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P3.x, P3.y);
	pOut->SetDrawColor(pIn, TriangleGfxInfo);

	TriangleGfxInfo.isFilled = true;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	//TriangleGfxInfo.DrawClr = pOut->getCrntDrawColor();
	//TriangleGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddTriangleAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Create a square  with the parameters read from the user
	CTriangle* R = new CTriangle(P1,P2, P3, TriangleGfxInfo);

	//Add the square to the list of figures
	pManager->AddFigure(R);
}
