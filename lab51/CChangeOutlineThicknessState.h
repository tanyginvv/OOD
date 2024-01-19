#pragma once
#include "CFillState.h"
#include "CDragAndDropState.h"
#include "CFillOutlineState.h"

class CChangeOutlineThicknessState : public IState {
public:
	void DragAndDrop(CToolbar* toolbar) const override;
	void Fill(CToolbar* toolbar) const override;
	void FillOutline(CToolbar* toolbar) const override;
	void ChangeOutlineThickness(CToolbar* toolbar) const override;
};