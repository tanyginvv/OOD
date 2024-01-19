#include "CButton.h"

CButton::CButton(
	Vector2f position, Vector2f sizeRectangle,
	Color buttonColor, ICommand* command, std::string text,
	int fontSize, Shape* shape, Color textColor
) :m_command(command), m_shape(shape) {
	m_rectangle.setPosition(position);
	m_rectangle.setSize(sizeRectangle);
	m_rectangle.setFillColor(buttonColor);

	if (m_font.loadFromFile("Roboto-Regular.ttf")) {
		m_text.setFont(m_font);
		m_text.setString(text);
		m_text.setFillColor(textColor);
		m_text.setCharacterSize(fontSize);
		m_text.setPosition(position);
	}
}

void CButton::Draw(RenderWindow& window) {
	window.draw(m_rectangle);
	window.draw(m_text);
	window.draw(*m_shape);
}

void CButton::SetCommand(ICommand* command) {
	m_command = command;
}

bool CButton::CursorInButton(Vector2f cursorPos) const {
	return m_rectangle.getGlobalBounds().contains(cursorPos);
}

void CButton::PressButton() {
	m_command->Execute();
}