#pragma once

#include "CFigureMovementDecorator.h"

class CBuider {
public:
	virtual void SetShape() = 0;
	virtual void SetPosition() = 0;
	virtual void SetFillColor();
	virtual void SetOutlineColor();
	virtual void SetOutlineThickness();

	CFigureMovementDecorator* GetShape();
protected:
	CFigureMovementDecorator* m_figure = nullptr;
	unsigned int m_fillColor;
	unsigned int m_outlineColor;
	float m_outlineThickness;
};