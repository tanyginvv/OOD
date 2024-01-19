#include "CChangeOutlineThicknessCommand.h"

CChangeOutlineThicknessCommand::CChangeOutlineThicknessCommand(CToolbar * toolbar)
	:m_toolbar(toolbar) {}

void CChangeOutlineThicknessCommand::Execute() const {
	m_toolbar->ChangeOutlineThickness();
}