#include "CFigureComposite.h"
#include "CFeatures.h"

CFigureComposite::CFigureComposite(const CFigureComposite& compoundFigureSrc) {
	auto newFigures = CFeatures::GetNewFigures(compoundFigureSrc.GetFigures());
	m_figures = newFigures;
}

CFigureComposite::CFigureComposite() {}

void CFigureComposite::Add(CFigureMovementDecorator* figure) {
	auto figureLocal = figure;
	figureLocal->SetMoved(false);
	m_figures.push_back(figureLocal);
}

FloatRect CFigureComposite::GetGlobalBounds() const {
	auto defaultFrame = m_figures.at(0)->GetGlobalBounds();
	Vector2f minPoint;
	minPoint.x = defaultFrame.left;
	minPoint.y = defaultFrame.top;

	Vector2f maxPoint;
	maxPoint.x = defaultFrame.left + defaultFrame.width;
	maxPoint.y = defaultFrame.top + defaultFrame.height;

	for (CFigureMovementDecorator* figure : m_figures) {
		auto localFrame = figure->GetGlobalBounds();

		if (localFrame.left < minPoint.x)
			minPoint.x = localFrame.left;
		if (localFrame.top < minPoint.y)
			minPoint.y = localFrame.top;
		if (localFrame.left + localFrame.width > maxPoint.x)
			maxPoint.x = localFrame.left + localFrame.width;
		if (localFrame.top + localFrame.height > maxPoint.y)
			maxPoint.y = localFrame.top + localFrame.height;
	}

	return FloatRect(minPoint.x, minPoint.y, abs(maxPoint.x - minPoint.x), abs(maxPoint.y - minPoint.y));
}

Vector2f CFigureComposite::GetPosition() const {
	auto globalBounds = GetGlobalBounds();

	return Vector2f(globalBounds.left, globalBounds.top);
}

void CFigureComposite::SetPosition(float x, float y) const {
	Vector2f d;
	d.x = x - GetPosition().x;
	d.y = y - GetPosition().y;

	for (auto figure : m_figures)
		figure->SetPosition(figure->GetPosition().x + d.x, figure->GetPosition().y + d.y);
}

void CFigureComposite::SetFillColor(Color color) const {
	for (auto figure : m_figures)
		figure->SetFillColor(color);
}

void CFigureComposite::SetOutlineColor(Color color) const {
	for (auto figure : m_figures)
		figure->SetOutlineColor(color);
}

void CFigureComposite::SetOutlineThickness(float thickness) const {
	for (auto figure : m_figures)
		figure->SetOutlineThickness(thickness);
}

void CFigureComposite::Draw(RenderWindow& window) const {
	if (GetMoved()) {
		FloatRect globalBounds = GetGlobalBounds();
		RectangleShape frame;
		frame.setSize(Vector2f(globalBounds.width, globalBounds.height));
		frame.setPosition(Vector2f(globalBounds.left, globalBounds.top));
		frame.setFillColor(sf::Color(0, 0, 0, 0));
		frame.setOutlineThickness(1);
		frame.setOutlineColor(Color::White);
		window.draw(frame);
		for (auto figure : m_figures)
			figure->Draw(window);
	}
	else
		for (auto figure : m_figures)
			figure->Draw(window);
}

std::vector<CFigureMovementDecorator*> CFigureComposite::GetFigures() const {
	return m_figures;
}

float CFigureComposite::GetPerimeter() const {
	float perimeter = 0;
	for (auto figure : m_figures) {
		perimeter += figure->GetPerimeter();
	}

	return perimeter;
}

float CFigureComposite::GetSquare() const {
	float square = 0;
	for (auto figure : m_figures) {
		square += figure->GetSquare();
	}

	return square;
}

std::string CFigureComposite::GetDescription() const {
	return groupedFigure + " P=" + std::to_string(GetPerimeter()) + "; S=" + std::to_string(round(GetSquare()));
}