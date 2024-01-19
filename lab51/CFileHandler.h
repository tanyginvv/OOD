#pragma once

#include <SFML/Graphics.hpp>
#include "CFigureMovementDecorator.h"
#include "CFiguresHandler.h"
#include "CSaveFileStrategy.h"
#include "CImportFileTemplate.h"

class CFileHandler {
public:
	CFileHandler(std::string filename, CFiguresHandler* figuresHandler, CSaveFileStrategy* saveFileStrategy, CImportFileTemplate* importFileStrategy);
	void Save();
	CFiguresMemento Import();
	void SetSaveFileStrategy(CSaveFileStrategy* saveFileStrategy);
	void SetImportFileStrategy(CImportFileTemplate* importFileStrategy);

	std::string GetTypeSaveFileStrategy();
	std::string GetTypeImportFileStrategy();

	CFiguresHandler* m_figuresHandler;
private:
	CSaveFileStrategy* m_saveFileStrategy;
	CImportFileTemplate* m_importFileStrategy;
	std::string m_filename;
};