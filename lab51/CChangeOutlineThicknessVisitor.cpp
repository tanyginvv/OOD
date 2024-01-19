#include "CChangeOutlineThicknessVisitor.h"

CChangeOutlineThicknessVisitor::CChangeOutlineThicknessVisitor(float thickness) :m_thickness(thickness) {}

void CChangeOutlineThicknessVisitor::VisitFigure(CFigureMovementDecorator* decorator) {
	decorator->SetOutlineThickness(m_thickness);
}