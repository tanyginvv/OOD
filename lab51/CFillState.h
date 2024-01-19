#pragma once
#include "IState.h"
#include "CFillOutlineState.h"
#include "CChangeOutlineThicknessState.h"
#include "CDragAndDropState.h"

class CFillState : public IState {
public:
	void DragAndDrop(CToolbar* toolbar) const override;
	void Fill(CToolbar* toolbar) const override;
	void FillOutline(CToolbar* toolbar) const override;
	void ChangeOutlineThickness(CToolbar* toolbar) const override;
};