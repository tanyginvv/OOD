#include "CCompoundBuilder.h"

CCompoundBuilder::CCompoundBuilder(std::vector<CFigureMovementDecorator*> figures)
	:m_figures(figures)
{}

void CCompoundBuilder::SetShape() {
	auto compoundFigure = new CFigureComposite();
	for (auto figure : m_figures)
		compoundFigure->Add(figure);
	m_figure = compoundFigure;
}

