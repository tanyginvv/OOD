#include "CFillVisitor.h"

CFillVisitor::CFillVisitor(Color color) :m_color(color) {}

void CFillVisitor::VisitFigure(CFigureMovementDecorator* decorator) {
	decorator->SetFillColor(m_color);
}