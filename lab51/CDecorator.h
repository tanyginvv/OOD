#pragma once
#include <string>

#include "CCanvas.h"

class CDecorator : public sf::Shape
{
public:
	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
	virtual std::string ToString() const = 0;
};

class CDecoratorTriangle : public sf::ConvexShape, public CDecorator
{
public:
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
private:
	CPoint m_vertex1;
	CPoint m_vertex2;
	CPoint m_vertex3;
};