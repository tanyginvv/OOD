#pragma once
#include "ICommand.h"
#include "CToolbar.h"

class CSetSelectedColorCommand : public ICommand {
public:
	CSetSelectedColorCommand(CToolbar* toolbar, Color color);
	void Execute() const override;
private:
	CToolbar* m_toolbar;
	Color m_color;
};