#pragma once
#include "ICommand.h"
#include "CToolbar.h"

class CSetSelectedThicknessCommand : public ICommand {
public:
	CSetSelectedThicknessCommand(CToolbar* toolbar, float thickness);
	void Execute() const override;
private:
	CToolbar* m_toolbar;
	float m_thickness;
};