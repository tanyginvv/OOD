#pragma once

#include "IVisitor.h"

class CFillOutlineVisitor : public IVisitor {
public:
	CFillOutlineVisitor(Color color);
	void VisitFigure(CFigureMovementDecorator* decorator) override;
private:
	Color m_color;
};