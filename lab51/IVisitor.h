#pragma once

#include "CFigureMovementDecorator.h"

class IVisitor {
public:
	virtual void VisitFigure(CFigureMovementDecorator* decorator) = 0;
};