#include "CFillCommand.h"

CFillCommand::CFillCommand(CToolbar* toolbar)
	:m_toolbar(toolbar) {}

void CFillCommand::Execute() const {
	m_toolbar->Fill();
}