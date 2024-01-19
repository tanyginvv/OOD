#pragma once
#include "CFillOutlineState.h"
#include "CChangeOutlineThicknessState.h"
#include "CFillState.h"

class CDragAndDropState : public IState {
public:
	void DragAndDrop(CToolbar* toolbar) const override;
	void Fill(CToolbar* toolbar) const override;
	void FillOutline(CToolbar* toolbar) const override;
	void ChangeOutlineThickness(CToolbar* toolbar) const override;
};