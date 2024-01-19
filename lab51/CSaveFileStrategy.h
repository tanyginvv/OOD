#pragma once

#include "CFigureMovementDecorator.h"
#include "CCircleDecorator.h"
#include "CRectangleDecorator.h"
#include "CTriangleDecorator.h"
#include "CFigureComposite.h"
#include "CConstants.h"
#include <sstream>
#include <fstream>

class CSaveFileStrategy {
public:
	virtual void Save(std::string filename, std::vector<CFigureMovementDecorator*> figures) = 0;
protected:
	void WriteFiguresInfo(std::ostream& output, std::vector<CFigureMovementDecorator*> figures);
	std::string GetCircleInfo(CCircleDecorator* circleDecorator);
	std::string GetRectangleInfo(CRectangleDecorator* rectangleDecorator);
	std::string GetTriangleInfo(CTriangleDecorator* triangleDecorator);
};