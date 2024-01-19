#include "CCreateRectangleFigureCommand.h"

CCreateRectangleFigureCommand::CCreateRectangleFigureCommand(CToolbar* toolbar)
	:m_toolbar(toolbar) {}

void CCreateRectangleFigureCommand::Execute() const {
	m_toolbar->m_figuresHandler->CreateRectangleFigure();
}