#include "CChangeOutlineThicknessState.h"

void CChangeOutlineThicknessState::DragAndDrop(CToolbar* toolbar) const {
	toolbar->SetState(new CDragAndDropState());
}

void CChangeOutlineThicknessState::Fill(CToolbar* toolbar) const {
	toolbar->SetState(new CFillState());
}

void CChangeOutlineThicknessState::FillOutline(CToolbar* toolbar) const {
	toolbar->SetState(new CFillOutlineState());
}

void CChangeOutlineThicknessState::ChangeOutlineThickness(CToolbar* toolbar) const {}