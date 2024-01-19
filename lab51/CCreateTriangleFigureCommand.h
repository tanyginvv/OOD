#pragma once
#include "ICommand.h"
#include "CToolbar.h"

class CCreateTriangleFigureCommand : public ICommand {
public:
	CCreateTriangleFigureCommand(CToolbar* toolbar);
	void Execute() const override;
private:
	CToolbar* m_toolbar;
};