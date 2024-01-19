#include "CFeatures.h"
#include "CCircleDecorator.h"
#include "CRectangleDecorator.h"
#include "CTriangleDecorator.h"
#include "CFigureComposite.h"

std::vector<CFigureMovementDecorator*> CFeatures::GetNewFigures(std::vector<CFigureMovementDecorator*> figures) {
	std::vector<CFigureMovementDecorator*> newFigures;

	for (auto figure : figures) {
		if (typeid(*figure) == typeid(CCircleDecorator))
			newFigures.push_back(new CCircleDecorator(*static_cast<CCircleDecorator*>(figure)));
		else if (typeid(*figure) == typeid(CRectangleDecorator))
			newFigures.push_back(new CRectangleDecorator(*static_cast<CRectangleDecorator*>(figure)));
		else if (typeid(*figure) == typeid(CTriangleDecorator))
			newFigures.push_back(new CTriangleDecorator(*static_cast<CTriangleDecorator*>(figure)));
		else if (typeid(*figure) == typeid(CFigureComposite))
			newFigures.push_back(new CFigureComposite(*static_cast<CFigureComposite*>(figure)));
	}

	return newFigures;
}