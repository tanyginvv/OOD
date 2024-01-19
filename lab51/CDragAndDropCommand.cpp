#include "CDragAndDropCommand.h"

CDragAndDropCommand::CDragAndDropCommand(CToolbar * toolbar)
	:m_toolbar(toolbar) {}

void CDragAndDropCommand::Execute() const {
	m_toolbar->DragAndDrop();
}