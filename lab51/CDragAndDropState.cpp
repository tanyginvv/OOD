#include "CDragAndDropState.h"

void CDragAndDropState::DragAndDrop(CToolbar* toolbar) const {}

void CDragAndDropState::Fill(CToolbar* toolbar) const {
	toolbar->SetState(new CFillState());
}

void CDragAndDropState::FillOutline(CToolbar* toolbar) const {
	toolbar->SetState(new CFillOutlineState());
}

void CDragAndDropState::ChangeOutlineThickness(CToolbar* toolbar) const {
	toolbar->SetState(new CChangeOutlineThicknessState());
}