#include "CRectangleDecorator.h";

CRectangleDecorator::CRectangleDecorator(RectangleShape* rectangle)
	:m_rectangle(rectangle),
	CFigureDecorator(rectangle) {}

CRectangleDecorator::CRectangleDecorator(const CRectangleDecorator& rectangleSrc) {
	auto oldRectangle = rectangleSrc.GetRectangle();
	auto newRectangle = new RectangleShape();
	newRectangle->setSize(oldRectangle->getSize());
	newRectangle->setPosition(oldRectangle->getPosition());
	newRectangle->setFillColor(oldRectangle->getFillColor());
	newRectangle->setOutlineColor(oldRectangle->getOutlineColor());
	newRectangle->setOutlineThickness(oldRectangle->getOutlineThickness());
	m_rectangle = newRectangle;
	m_shape = newRectangle;
}

void CRectangleDecorator::SetSize(Vector2f size) const {
	m_rectangle->setSize(size);
}

float CRectangleDecorator::GetPerimeter() const {
	Vector2f size = m_rectangle->getSize();
	return (size.x + size.y) * 2;
}

float CRectangleDecorator::GetSquare() const {
	Vector2f size = m_rectangle->getSize();
	return size.x * size.y;
}

std::string CRectangleDecorator::GetDescription() const {
	return rectangle + ": P=" + std::to_string(GetPerimeter()) + "; S=" + std::to_string(round(GetSquare()));
}

RectangleShape* CRectangleDecorator::GetRectangle() const {
	return m_rectangle;
}