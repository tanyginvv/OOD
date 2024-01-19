#pragma once
#include "CFiguresHandler.h"
#include "CButton.h"

class IState;

class CToolbar {
public:
	CToolbar(IState* state, RenderWindow& window, CFiguresHandler* figureHandler);

	void DragAndDrop();
	void Fill();
	void FillOutline();
	void ChangeOutlineThickness();

	void Draw();

	void SetState(IState* state);
	void SetSelectedColor(Color color);
	void SetSelectedThickness(float thickness);

	IState* GetState() const;
	Color GetSelectedColor() const;
	float GetSelectedThickness() const;
	std::vector<CButton*> GetButtons() const;

	void SetCursorPosition(Vector2i pos);
	bool PressToolButton() const;

	CFiguresHandler* m_figuresHandler;
private:
	std::vector<CButton*> m_buttons;
	Color m_selectedColor = Color::White;
	float m_selectedThickness = 1;
	IState* m_state;
	RenderWindow& m_window;
	Vector2i m_cursorPosition;
};