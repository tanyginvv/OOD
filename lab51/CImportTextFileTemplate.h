#pragma once

#include "CImportFileTemplate.h"

class CImportTextFileTemplate : public CImportFileTemplate {
public:
	CFiguresMemento Import(std::string filename) override;
};