#pragma once

#include "IVisitor.h"

class CFillVisitor : public IVisitor {
public:
	CFillVisitor(Color color);
	void VisitFigure(CFigureMovementDecorator* decorator) override;
private:
	Color m_color;
};