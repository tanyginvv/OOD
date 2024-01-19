#pragma once
#include "ICommand.h"
#include "CToolbar.h"

class CCreateCircleFigureCommand : public ICommand {
public:
	CCreateCircleFigureCommand(CToolbar* toolbar);
	void Execute() const override;
private:
	CToolbar* m_toolbar;
};