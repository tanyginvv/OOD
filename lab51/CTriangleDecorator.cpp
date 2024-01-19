#include "CTriangleDecorator.h"

CTriangleDecorator::CTriangleDecorator(ConvexShape* triangle)
	:m_triangle(triangle),
	CFigureDecorator(triangle) {}

CTriangleDecorator::CTriangleDecorator(const CTriangleDecorator& triangleSrc) {
	auto oldTriangle = triangleSrc.GetTriangle();
	auto newTriangle = new ConvexShape();
	newTriangle->setPointCount(oldTriangle->getPointCount());
	newTriangle->setPoint(0, oldTriangle->getPoint(0));
	newTriangle->setPoint(1, oldTriangle->getPoint(1));
	newTriangle->setPoint(2, oldTriangle->getPoint(2));

	newTriangle->setPosition(oldTriangle->getPosition());
	newTriangle->setFillColor(oldTriangle->getFillColor());
	newTriangle->setOutlineColor(oldTriangle->getOutlineColor());
	newTriangle->setOutlineThickness(oldTriangle->getOutlineThickness());
	m_triangle = newTriangle;
	m_shape = newTriangle;
}

float CTriangleDecorator::GetVectorLength(Vector2f point1, Vector2f point2) const {
	return sqrt((point2.x - point1.x) * (point2.x - point1.x) + (point2.y - point1.y) * (point2.y - point1.y));
}

void CTriangleDecorator::SetPointCount(size_t count) const {
	m_triangle->setPointCount(count);
}

void CTriangleDecorator::SetPoint(size_t index, Vector2f point) const {
	m_triangle->setPoint(index, point);
}

float CTriangleDecorator::GetPerimeter() const {
	Vector2f point0 = m_triangle->getPoint(0);
	Vector2f point1 = m_triangle->getPoint(1);
	Vector2f point2 = m_triangle->getPoint(2);

	return GetVectorLength(point0, point1)
		+ GetVectorLength(point0, point2)
		+ GetVectorLength(point1, point2);
}

float CTriangleDecorator::GetSquare() const {
	Vector2f point0 = m_triangle->getPoint(0);
	Vector2f point1 = m_triangle->getPoint(1);
	Vector2f point2 = m_triangle->getPoint(2);
	float sideLength1 = GetVectorLength(point0, point1);
	float sideLength2 = GetVectorLength(point0, point2);
	float sideLength3 = GetVectorLength(point1, point2);
	float semiPerimeter = GetPerimeter() / 2;
	return sqrt(semiPerimeter * (semiPerimeter - sideLength1)
		* (semiPerimeter - sideLength2) * (semiPerimeter - sideLength3));
}

std::string CTriangleDecorator::GetDescription() const {
	return triangle + ": P=" + std::to_string(GetPerimeter()) + "; S=" + std::to_string(round(GetSquare()));
}

ConvexShape* CTriangleDecorator::GetTriangle() const {
	return m_triangle;
}