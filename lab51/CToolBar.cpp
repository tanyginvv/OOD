#include "CToolbar.h"
#include "IState.h"
#include "CDragAndDropCommand.h"
#include "CFillCommand.h"
#include "CFillOutlineCommand.h"
#include "CChangeOutlineThicknessCommand.h"
#include "CCreateCircleFigureCommand.h"
#include "CCreateRectangleFigureCommand.h"
#include "CCreateTriangleFigureCommand.h"
#include "CSetSelectedColorCommand.h"
#include "CSetSelectedThicknessCommand.h"

CToolbar::CToolbar(IState* state, RenderWindow& window, CFiguresHandler* figureHandler)
	:m_window(window),
	m_figuresHandler(figureHandler),
	m_state(state)
{

	m_buttons.push_back(new CButton(Vector2f(643, 10), Vector2f(BTN_HEIGHTS,	BTN_WIDTHS), Color::White, new CDragAndDropCommand(this), "Drag&Drop", 20));
	m_buttons.push_back(new CButton(Vector2f(851, 10), Vector2f(BTN_HEIGHTS, BTN_WIDTHS), Color::White, new CFillCommand(this), "Fill shape", 20));
	m_buttons.push_back(new CButton(Vector2f(1064, 10), Vector2f(BTN_HEIGHTS, BTN_WIDTHS), Color::White, new CFillOutlineCommand(this), "Fill outline", 20));
	m_buttons.push_back(new CButton(Vector2f(1287, 10), Vector2f(BTN_HEIGHTS, BTN_WIDTHS), Color::White, new CChangeOutlineThicknessCommand(this), "Change thickness", 20));

	m_buttons.push_back(new CButton(Vector2f(19, 68), Vector2f(BTN_HEIGHT, BTN_WIDTH), Color::Red, new CSetSelectedColorCommand(this, Color::Red)));
	m_buttons.push_back(new CButton(Vector2f(143, 68), Vector2f(BTN_HEIGHT, BTN_WIDTH), Color::Green, new CSetSelectedColorCommand(this, Color::Green)));
	m_buttons.push_back(new CButton(Vector2f(267, 68), Vector2f(BTN_HEIGHT, BTN_WIDTH), Color::Yellow, new CSetSelectedColorCommand(this, Color::Yellow)));
	m_buttons.push_back(new CButton(Vector2f(391, 68), Vector2f(BTN_HEIGHT, BTN_WIDTH), Color::Blue, new CSetSelectedColorCommand(this, Color::Blue)));
	m_buttons.push_back(new CButton(Vector2f(515, 68), Vector2f(BTN_HEIGHT, BTN_WIDTH), Color::Cyan, new CSetSelectedColorCommand(this, Color::Cyan)));

	m_buttons.push_back(new CButton(Vector2f(1053, 68), Vector2f(212, BTN_WIDTH), Color::White, new CSetSelectedThicknessCommand(this, 1), "Less", 20));
	m_buttons.push_back(new CButton(Vector2f(1269, 68), Vector2f(212, BTN_WIDTH), Color::White, new CSetSelectedThicknessCommand(this, 2), "More", 20));
;
	m_buttons.push_back(new CButton(Vector2f(19, 10), Vector2f(BTN_HEIGHTS, BTN_WIDTHS), Color::White, new CCreateCircleFigureCommand(this), "Create Circle", 20));

	m_buttons.push_back(new CButton(Vector2f(435, 10), Vector2f(BTN_HEIGHTS, BTN_WIDTHS), Color::White, new CCreateRectangleFigureCommand(this), "Create Rectangle", 20));

	m_buttons.push_back(new CButton(Vector2f(227, 10), Vector2f(BTN_HEIGHTS, BTN_WIDTHS), Color::White, new CCreateTriangleFigureCommand(this), "Create Triangle", 20));
}

void CToolbar::DragAndDrop() {
	m_state->DragAndDrop(this);
}

void CToolbar::Fill() {
	m_state->Fill(this);
}

void CToolbar::FillOutline() {
	m_state->FillOutline(this);
}

void CToolbar::ChangeOutlineThickness() {
	m_state->ChangeOutlineThickness(this);
}

void CToolbar::Draw() {
	for (auto button : m_buttons) {
		button->Draw(m_window);
	}
}

void CToolbar::SetState(IState* state) {
	m_state = state;
}

void CToolbar::SetSelectedColor(Color color) {
	m_selectedColor = color;
}

void CToolbar::SetSelectedThickness(float thickness) {
	m_selectedThickness = thickness;
}

IState* CToolbar::GetState() const {
	return m_state;
}

Color CToolbar::GetSelectedColor() const {
	return m_selectedColor;
}

float CToolbar::GetSelectedThickness() const {
	return m_selectedThickness;
}

std::vector<CButton*> CToolbar::GetButtons() const {
	return m_buttons;
}

void CToolbar::SetCursorPosition(Vector2i pos) {
	m_cursorPosition = pos;
}

bool CToolbar::PressToolButton() const {
	for (auto button : m_buttons) {
		if (button->CursorInButton(static_cast<Vector2f>(m_cursorPosition))) {
			button->PressButton();
			return true;
		}
	}

	return false;
}