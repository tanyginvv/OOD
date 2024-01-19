#include "CFillOutlineState.h"

void CFillOutlineState::DragAndDrop(CToolbar* toolbar) const {
	toolbar->SetState(new CDragAndDropState());
}

void CFillOutlineState::Fill(CToolbar* toolbar) const {
	toolbar->SetState(new CFillState());
}

void CFillOutlineState::FillOutline(CToolbar* toolbar) const {}

void CFillOutlineState::ChangeOutlineThickness(CToolbar* toolbar) const {
	toolbar->SetState(new CChangeOutlineThicknessState());
}