#include "CFiguresCreator.h"

void CFiguresCreator::SetBuider(CBuider* buider) {
	m_buider = buider;
}

CFigureMovementDecorator* CFiguresCreator::CreateAndGetFigure() {
	m_buider->SetShape();
	m_buider->SetPosition();
	m_buider->SetFillColor();
	m_buider->SetOutlineColor();
	m_buider->SetOutlineThickness();
	return m_buider->GetShape();
}
