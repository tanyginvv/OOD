#pragma once

#include <SFML/Graphics.hpp>
#include "CFiguresHandler.h"
#include "CToolbar.h"
#include "CDragAndDropState.h"
#include "CFillVisitor.h"
#include "CFillOutlineVisitor.h"
#include "CChangeOutlineThicknessVisitor.h"
#include "CFileHandler.h"
#include "CSaveTextFileStrategy.h"
#include "CSaveBinaryFileStrategy.h"
#include "CImportTextFileTemplate.h"
#include "CImportBinaryFileTemplate.h"

using namespace sf;

class CApplication {
public:
	static CApplication* GetInstance(std::istream& input, std::ostream& output, RenderWindow& window);

	void ReadFigures();
	void ProcessAnEvent(Event event);
	void PrintFiguresInfo();

private:
	CApplication(std::istream& input, std::ostream& output, RenderWindow& window);

	void Render();
	void DrawApplication();

	static CApplication* m_instance;
	std::istream& m_input;
	std::ostream& m_output;
	RenderWindow& m_window;

	CFiguresHandler* m_figuresHandler;
	CToolbar* m_toolbar;
	CFileHandler* m_fileHandler;
};