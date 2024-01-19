#include "CFillOutlineCommand.h"

CFillOutlineCommand::CFillOutlineCommand(CToolbar* toolbar)
	:m_toolbar(toolbar) {}

void CFillOutlineCommand::Execute() const {
	m_toolbar->FillOutline();
}