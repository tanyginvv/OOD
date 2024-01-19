#pragma once
#include "ICommand.h"
#include "CToolbar.h"

class CCreateRectangleFigureCommand : public ICommand {
public:
	CCreateRectangleFigureCommand(CToolbar* toolbar);
	void Execute() const override;
private:
	CToolbar* m_toolbar;
};