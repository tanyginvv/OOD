#pragma once

#include "CFigureMovementDecorator.h"
#include <vector>

class CFiguresMemento {
public:
	CFiguresMemento(
		std::vector<CFigureMovementDecorator*> figures,
		std::vector<CFigureMovementDecorator*> selectedFigures
	);
	std::vector<CFigureMovementDecorator*> GetFigures() const;
	std::vector<CFigureMovementDecorator*> GetSelectedFigures() const;
private:
	std::vector<CFigureMovementDecorator*> m_figures;
	std::vector<CFigureMovementDecorator*> m_selectedFigures;
};