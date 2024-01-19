#pragma once
#include "ICommand.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

using namespace sf;

class CButton {
public:
	CButton(
		Vector2f position, Vector2f sizeRectangle,
		Color buttonColor, ICommand* command, std::string text = "",
		int fontSize = 0,
		Shape* shape = new CircleShape,
		Color textColor = Color::Black
	);
	void Draw(RenderWindow& window);
	void SetCommand(ICommand* command);
	bool CursorInButton(Vector2f cursorPos) const;
	void PressButton();
private:
	RectangleShape m_rectangle;
	Text m_text;
	Font m_font;
	Shape* m_shape;
	ICommand* m_command;
};