#pragma once

#include "CFiguresMemento.h"
#include "CFiguresCreator.h"
#include "CConstants.h"
#include "CCircleBuilder.h"
#include "CRectangleBuilder.h"
#include "CCompoundBuilder.h"
#include "CTriangleBuilder.h"
#include <sstream>
#include <fstream>

class CImportFileTemplate {
public:
	virtual CFiguresMemento Import(std::string filename) = 0;
protected:
	std::vector<CFigureMovementDecorator*> GetFiguresFromFile(std::istream& input);
};