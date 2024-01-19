#include "CCircleDecorator.h"
#define _USE_MATH_DEFINES
#include <math.h>

CCircleDecorator::CCircleDecorator(CircleShape* circle)
	:m_circle(circle),
	CFigureDecorator(circle) {}

CCircleDecorator::CCircleDecorator(const CCircleDecorator& circleSrc) {
	auto oldCircle = circleSrc.GetCircle();
	auto newCircle = new CircleShape(oldCircle->getRadius());
	newCircle->setPosition(oldCircle->getPosition());
	newCircle->setFillColor(oldCircle->getFillColor());
	newCircle->setOutlineColor(oldCircle->getOutlineColor());
	newCircle->setOutlineThickness(oldCircle->getOutlineThickness());
	m_circle = newCircle;
	m_shape = newCircle;
};

void CCircleDecorator::SetRadius(float r) const {
	m_circle->setRadius(r);
}

float CCircleDecorator::GetPerimeter() const {
	return 2 * M_PI * m_circle->getRadius();
}

float CCircleDecorator::GetSquare() const {
	float radius = m_circle->getRadius();
	return M_PI * radius * radius;
}

std::string CCircleDecorator::GetDescription() const {
	return circle + ": P=" + std::to_string(GetPerimeter()) + "; S=" + std::to_string(round(GetSquare()));
}

CircleShape* CCircleDecorator::GetCircle() const {
	return m_circle;
}