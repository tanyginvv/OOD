#pragma once
#include "ICommand.h"
#include "CToolbar.h"

class CFillCommand : public ICommand {
public:
	CFillCommand(CToolbar* toolbar);
	void Execute() const override;
private:
	CToolbar* m_toolbar;
};