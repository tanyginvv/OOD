#include "CFillOutlineVisitor.h"

CFillOutlineVisitor::CFillOutlineVisitor(Color color) :m_color(color) {}

void CFillOutlineVisitor::VisitFigure(CFigureMovementDecorator* decorator) {
	decorator->SetOutlineColor(m_color);
}