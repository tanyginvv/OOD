#pragma once
#include <string>
#include <memory>
#include <SFML/Graphics.hpp>
#include <math.h>
#include "CConstants.h"
#include <fstream>

using namespace sf;

class CFigureMovementDecorator {
public:
	virtual void SetPosition(float x, float y) const = 0;
	virtual void SetFillColor(Color color) const = 0;
	virtual void SetOutlineColor(Color color) const = 0;
	virtual void SetOutlineThickness(float thickness) const = 0;
	void SetMoved(bool isMoved);

	virtual void Draw(RenderWindow& window) const = 0;

	virtual FloatRect GetGlobalBounds() const = 0;
	virtual Vector2f GetPosition() const = 0;
	virtual std::string GetDescription() const = 0;
	bool GetMoved() const;
	virtual float GetPerimeter() const = 0;
	virtual float GetSquare() const = 0;
private:
	bool m_isMoved = false;
};