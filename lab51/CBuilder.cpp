#include "CBuilder.h"

CFigureMovementDecorator* CBuider::GetShape() {
	return m_figure;
}

void CBuider::SetFillColor() {
	m_figure->SetFillColor(Color(m_fillColor));
}

void CBuider::SetOutlineColor() {
	m_figure->SetOutlineColor(Color(m_outlineColor));
}

void CBuider::SetOutlineThickness() {
	m_figure->SetOutlineThickness(m_outlineThickness);
}