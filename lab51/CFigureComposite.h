#pragma once
#include "CFigureMovementDecorator.h"
using namespace sf;

const std::string groupedFigure = "Grouped shape:";

class CFigureComposite : public CFigureMovementDecorator {
public:
	CFigureComposite(const CFigureComposite& compoundFigureSrc);
	CFigureComposite();
	void Add(CFigureMovementDecorator* figure);
	void SetPosition(float x, float y) const override;
	void SetFillColor(Color color) const override;
	void SetOutlineColor(Color color) const override;
	void SetOutlineThickness(float thickness) const override;
	void Draw(RenderWindow& window) const override;

	std::string GetDescription() const override;
	FloatRect GetGlobalBounds() const override;
	Vector2f GetPosition() const override;
	std::vector<CFigureMovementDecorator*> GetFigures() const;
	float GetPerimeter() const override;
	float GetSquare() const override;
private:
	std::vector<CFigureMovementDecorator*> m_figures;
};