#include "CFiguresMemento.h"

CFiguresMemento::CFiguresMemento(
	std::vector<CFigureMovementDecorator*> figures,
	std::vector<CFigureMovementDecorator*> selectedFigures
) :m_figures(figures), m_selectedFigures(selectedFigures) {};

std::vector<CFigureMovementDecorator*> CFiguresMemento::GetFigures() const {
	return m_figures;
}

std::vector<CFigureMovementDecorator*> CFiguresMemento::GetSelectedFigures() const {
	return m_selectedFigures;
}