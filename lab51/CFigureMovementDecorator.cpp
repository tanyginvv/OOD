#include "CFigureMovementDecorator.h"

void CFigureMovementDecorator::SetMoved(bool isMoved) {
	m_isMoved = isMoved;
}

bool CFigureMovementDecorator::GetMoved() const {
	return m_isMoved;
}