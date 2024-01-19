#pragma once
#include "ICommand.h"
#include "CToolbar.h"

class CChangeOutlineThicknessCommand : public ICommand {
public:
	CChangeOutlineThicknessCommand(CToolbar* toolbar);
	void Execute() const override;
private:
	CToolbar* m_toolbar;
};