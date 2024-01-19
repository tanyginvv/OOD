#include "CFillState.h"

void CFillState::DragAndDrop(CToolbar* toolbar) const {
	toolbar->SetState(new CDragAndDropState());
}

void CFillState::Fill(CToolbar* toolbar) const {}

void CFillState::FillOutline(CToolbar* toolbar) const {
	toolbar->SetState(new CFillOutlineState());
}

void CFillState::ChangeOutlineThickness(CToolbar* toolbar) const {
	toolbar->SetState(new CChangeOutlineThicknessState());
}