#pragma once
#include "ICommand.h"
#include "CToolbar.h"

class CFillOutlineCommand : public ICommand {
public:
	CFillOutlineCommand(CToolbar* toolbar);
	void Execute() const override;
private:
	CToolbar* m_toolbar;
};