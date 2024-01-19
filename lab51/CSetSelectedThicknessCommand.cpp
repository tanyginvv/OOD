#include "CSetSelectedThicknessCommand.h"

CSetSelectedThicknessCommand::CSetSelectedThicknessCommand(CToolbar* toolbar, float thickness)
	:m_toolbar(toolbar),
	m_thickness(thickness) {}

void CSetSelectedThicknessCommand::Execute() const {
	m_toolbar->SetSelectedThickness(m_thickness);
}