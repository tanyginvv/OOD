#include "CCreateTriangleFigureCommand.h"

CCreateTriangleFigureCommand::CCreateTriangleFigureCommand(CToolbar* toolbar)
	:m_toolbar(toolbar) {}

void CCreateTriangleFigureCommand::Execute() const {
	m_toolbar->m_figuresHandler->CreateTriangleFigure();
}