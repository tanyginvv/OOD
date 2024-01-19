#pragma once

#include "IVisitor.h"

class CChangeOutlineThicknessVisitor : public IVisitor {
public:
	CChangeOutlineThicknessVisitor(float thickness);
	void VisitFigure(CFigureMovementDecorator* decorator) override;
private:
	float m_thickness;
};