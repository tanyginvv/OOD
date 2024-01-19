#pragma once
#include "CToolbar.h"

class CToolbar;

class IState {
public:
	virtual void DragAndDrop(CToolbar* toolbar) const = 0;
	virtual void Fill(CToolbar* toolbar) const = 0;
	virtual void FillOutline(CToolbar* toolbar) const = 0;
	virtual void ChangeOutlineThickness(CToolbar* toolbar) const = 0;
};