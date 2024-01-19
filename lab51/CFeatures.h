#pragma once

#include <vector>
#include "CFigureMovementDecorator.h"

class CFeatures {
public:
	static std::vector<CFigureMovementDecorator*> GetNewFigures(std::vector<CFigureMovementDecorator*> figures);
};