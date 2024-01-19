#pragma once
#include "CFillState.h"
#include "CChangeOutlineThicknessState.h"
#include "CDragAndDropState.h"

class CFillOutlineState : public IState {
public:
	void DragAndDrop(CToolbar* toolbar) const override;
	void Fill(CToolbar* toolbar) const override;
	void FillOutline(CToolbar* toolbar) const override;
	void ChangeOutlineThickness(CToolbar* toolbar) const override;
};