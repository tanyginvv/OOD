#include "CFigureDecorator.h"

CFigureDecorator::CFigureDecorator(Shape* shape)
	:m_shape(shape) {}

CFigureDecorator::CFigureDecorator() {}

void CFigureDecorator::SetFillColor(Color color) const {
	m_shape->setFillColor(color);
}

void CFigureDecorator::SetOutlineColor(Color color) const {
	m_shape->setOutlineColor(color);
}

void CFigureDecorator::SetOutlineThickness(float thickness) const {
	m_shape->setOutlineThickness(thickness);
}

void CFigureDecorator::SetPosition(float x, float y) const {
	m_shape->setPosition(x, y);
}

void CFigureDecorator::Draw(RenderWindow& window) const {
	if (GetMoved()) {
		FloatRect globalBounds = GetGlobalBounds();
		RectangleShape frame;
		frame.setSize(Vector2f(globalBounds.width, globalBounds.height));
		frame.setPosition(Vector2f(globalBounds.left, globalBounds.top));
		frame.setFillColor(sf::Color(0, 0, 0, 0));
		frame.setOutlineThickness(1);
		frame.setOutlineColor(Color::White);
		window.draw(frame);
		window.draw(*m_shape);
	}
	else
		window.draw(*m_shape);
}

FloatRect CFigureDecorator::GetGlobalBounds() const {
	return m_shape->getGlobalBounds();
}

Vector2f CFigureDecorator::GetPosition() const {
	return m_shape->getPosition();
}