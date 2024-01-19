#pragma once

#include "CBuilder.h"
#include "CFigureComposite.h"

class CCompoundBuilder : public CBuider {
public:
	CCompoundBuilder(std::vector<CFigureMovementDecorator*> figures);
	void SetShape() override;
	void SetPosition() override {};
	void SetFillColor() override {};
	void SetOutlineColor() override {};
	void SetOutlineThickness() override {};
private:
	std::vector<CFigureMovementDecorator*> m_figures;
};