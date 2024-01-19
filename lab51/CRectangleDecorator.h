#pragma once
#include "CFigureDecorator.h";

class CRectangleDecorator : public CFigureDecorator {
public:
	CRectangleDecorator() {};
	CRectangleDecorator(RectangleShape* rectangle);
	CRectangleDecorator(const CRectangleDecorator& rectangleSrc);
	std::string GetDescription() const override;
	void SetSize(Vector2f size) const;

	RectangleShape* GetRectangle() const;
	float GetPerimeter() const override;
	float GetSquare() const override;
private:
	RectangleShape* m_rectangle;
};