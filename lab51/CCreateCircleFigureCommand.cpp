#include "CCreateCircleFigureCommand.h"

CCreateCircleFigureCommand::CCreateCircleFigureCommand(CToolbar* toolbar)
	:m_toolbar(toolbar) {}

void CCreateCircleFigureCommand::Execute() const {
	m_toolbar->m_figuresHandler->CreateCircleFigure();
}