#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "CFigureMovementDecorator.h"
#include "CCircleDecorator.h"
#include "CRectangleDecorator.h"
#include "CTriangleDecorator.h"
#include "CFigureComposite.h"
#include "CFiguresMemento.h"
#include "IVisitor.h"
#include "CConstants.h"
#include <sstream>
#include <stack>

class CFiguresHandler {
public:
	CFiguresHandler(RenderWindow& window);
	void CreatingFigures(std::stringstream& ss);
	void CreateCircleFigure();
	void CreateRectangleFigure();
	void CreateTriangleFigure();

	void SelectFigures();
	void SelectFigure();
	void UnselectFigure();
	void UnselectFigures();

	void Accept(IVisitor* visitor);

	void MoveFigure();
	void ResetTheIndexMovableFigure();

	void GroupFigures();
	void UngroupFigures();

	void SetCursorPosition(Vector2i pos);
	void SetDx(float dX);
	void SetDy(float dY);

	void SaveHistory();
	void UndoHistory();
	void ImportMemento(CFiguresMemento memento);

	void Draw();
	std::vector<CFigureMovementDecorator*> GetFigures() const;
private:
	std::vector<CFigureMovementDecorator*> m_figures;
	std::vector<CFigureMovementDecorator*> m_selectedFigures;
	int m_indexMovableFigure = -1;
	Vector2i m_cursorPosition;
	float m_dX = 0;
	float m_dY = 0;
	RenderWindow& m_window;
	std::stack<CFiguresMemento> m_history;
};