#include "CSetSelectedColorCommand.h"

CSetSelectedColorCommand::CSetSelectedColorCommand(CToolbar* toolbar, Color color)
	:m_toolbar(toolbar),
	m_color(color) {}

void CSetSelectedColorCommand::Execute() const {
	m_toolbar->SetSelectedColor(m_color);
}