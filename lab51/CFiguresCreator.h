#pragma once

#include "CBuilder.h"
#include "CFigureMovementDecorator.h"

class CFiguresCreator {
public:
	void SetBuider(CBuider* buider);
	CFigureMovementDecorator* CreateAndGetFigure();
private:
	CBuider* m_buider;
};