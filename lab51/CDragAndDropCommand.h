#pragma once
#include "ICommand.h"
#include "CToolbar.h"

class CDragAndDropCommand : public ICommand {
public:
	CDragAndDropCommand(CToolbar* toolbar);
	void Execute() const override;
private:
	CToolbar* m_toolbar;
};