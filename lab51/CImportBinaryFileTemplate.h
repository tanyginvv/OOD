#pragma once

#include "CImportFileTemplate.h"

class CImportBinaryFileTemplate : public CImportFileTemplate {
public:
	CFiguresMemento Import(std::string filename) override;
};