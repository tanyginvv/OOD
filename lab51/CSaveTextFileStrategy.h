#pragma once

#include "CSaveFileStrategy.h"

class CSaveTextFileStrategy : public CSaveFileStrategy {
public:
	void Save(std::string filename, std::vector<CFigureMovementDecorator*> figures) override;
};