#include "CFiguresHandler.h"
#include "CFeatures.h"

CFiguresHandler::CFiguresHandler(RenderWindow& window)
	:m_window(window) {}

void CFiguresHandler::CreatingFigures(std::stringstream& ss) {
	std::string figureType;
	ss >> figureType;

	if (figureType == circle) {
		SaveHistory();
		float x, y, r;
		ss >> x >> y >> r;
		CCircleDecorator* circleDecorator = new CCircleDecorator(new CircleShape());
		circleDecorator->SetRadius(r);
		circleDecorator->SetPosition(x, y);
		circleDecorator->SetFillColor(Color::Blue);
		m_figures.push_back(circleDecorator);
	}

	if (figureType == rectangle) {
		SaveHistory();
		float x1, y1, x2, y2;
		ss >> x1 >> y1 >> x2 >> y2;
		CRectangleDecorator* rectangleDecorator = new CRectangleDecorator(new RectangleShape());
		rectangleDecorator->SetSize(Vector2f(x2 - x1, y2 - y1));
		rectangleDecorator->SetPosition((x2 - x1) / 2, (y2 - y1) / 2);
		rectangleDecorator->SetFillColor(Color::Blue);
		m_figures.push_back(rectangleDecorator);
	}

	if (figureType == triangle) {
		SaveHistory();
		sf::Vector2f point1, point2, point3;
		ss >> point1.x >> point1.y >> point2.x >> point2.y >> point3.x >> point3.y;
		CTriangleDecorator* triangleDecorator = new CTriangleDecorator(new ConvexShape());
		triangleDecorator->SetPointCount(3);
		triangleDecorator->SetPoint(0, point1);
		triangleDecorator->SetPoint(1, point2);
		triangleDecorator->SetPoint(2, point3);
		triangleDecorator->SetPosition((point1.x + point2.x + point3.x) / 3, (point1.y + point2.y + point3.y) / 3);
		triangleDecorator->SetFillColor(Color::Blue);
		m_figures.push_back(std::move(triangleDecorator));
	}
}

void CFiguresHandler::CreateCircleFigure() {
	SaveHistory();
	CCircleDecorator* circleDecorator = new CCircleDecorator(new CircleShape());
	circleDecorator->SetRadius(50);
	circleDecorator->SetPosition(defaultX, defaultY);
	circleDecorator->SetFillColor(Color::Blue);
	m_figures.push_back(circleDecorator);
}

void CFiguresHandler::CreateRectangleFigure() {
	SaveHistory();
	CRectangleDecorator* rectangleDecorator = new CRectangleDecorator(new RectangleShape());
	rectangleDecorator->SetSize(Vector2f(100, 100));
	rectangleDecorator->SetPosition(defaultX - 50, defaultY - 20);
	rectangleDecorator->SetFillColor(Color::Cyan);
	m_figures.push_back(rectangleDecorator);
}

void CFiguresHandler::CreateTriangleFigure() {
	SaveHistory();
	CTriangleDecorator* triangleDecorator = new CTriangleDecorator(new ConvexShape());
	triangleDecorator->SetPointCount(3);
	triangleDecorator->SetPoint(0, Vector2f(100, 10));
	triangleDecorator->SetPoint(1, Vector2f(50, 110));
	triangleDecorator->SetPoint(2, Vector2f(150, 110));
	triangleDecorator->SetPosition(defaultX, defaultY + 20);
	triangleDecorator->SetFillColor(Color::Red);
	m_figures.push_back(std::move(triangleDecorator));
}

void CFiguresHandler::SetCursorPosition(Vector2i pos) {
	m_cursorPosition = pos;
}

void CFiguresHandler::SetDx(float dX) {
	m_dX = dX;
}

void CFiguresHandler::SetDy(float dY) {
	m_dY = dY;
}

void CFiguresHandler::SelectFigures() {
	for (size_t i = 0; i < m_figures.size(); i++)
		if (m_figures[i]->GetGlobalBounds().contains(m_cursorPosition.x, m_cursorPosition.y)) {
			m_figures[i]->SetMoved(true);
			m_selectedFigures.push_back(m_figures[i]);
		}
}

void CFiguresHandler::SelectFigure() {
	for (size_t i = 0; i < m_figures.size(); i++)
		if (m_figures[i]->GetGlobalBounds().contains(m_cursorPosition.x, m_cursorPosition.y)) {
			SaveHistory();
			if (m_figures[i]->GetMoved()) {
				m_indexMovableFigure = i;
				m_dX = m_cursorPosition.x - m_figures[i]->GetPosition().x;
				m_dY = m_cursorPosition.y - m_figures[i]->GetPosition().y;
			}
			else {
				m_indexMovableFigure = i;
				m_figures[i]->SetMoved(true);
				m_selectedFigures.clear();
				m_selectedFigures.push_back(m_figures[i]);
				m_dX = m_cursorPosition.x - m_figures[i]->GetPosition().x;
				m_dY = m_cursorPosition.y - m_figures[i]->GetPosition().y;
				for (size_t j = 0; j < m_figures.size(); j++)
					if (j != i)
						m_figures[j]->SetMoved(false);
			}
		}
}

void CFiguresHandler::UnselectFigure() {
	for (size_t i = 0; i < m_figures.size(); i++)
	{
		if (m_figures[i]->GetGlobalBounds().contains(m_cursorPosition.x, m_cursorPosition.y)) {
			if (m_figures[i]->GetMoved()) {
				m_figures[i]->SetMoved(false);
				m_indexMovableFigure = -1;
				std::vector<CFigureMovementDecorator*>::iterator it = find(m_selectedFigures.begin(), m_selectedFigures.end(), m_figures[i]);
				if (it != m_selectedFigures.end())
					m_selectedFigures.erase(it);
			}
		}
	}
}

void CFiguresHandler::UnselectFigures() {
	for (auto figure : m_figures) {
		figure->SetMoved(false);
	}
	m_indexMovableFigure = -1;
	m_selectedFigures.clear();
}

void CFiguresHandler::Accept(IVisitor* visitor) {
	for (auto figure : m_figures) {
		if (figure->GetGlobalBounds().contains(m_cursorPosition.x, m_cursorPosition.y)) {
			SaveHistory();
			visitor->VisitFigure(figure);
		}
	}
}

void CFiguresHandler::ResetTheIndexMovableFigure() {
	if (m_indexMovableFigure != -1)
		m_indexMovableFigure = -1;
}

void CFiguresHandler::GroupFigures() {
	if (!m_selectedFigures.empty()) {
		SaveHistory();
		CFigureComposite* compoundFigure = new CFigureComposite;
		for (CFigureMovementDecorator* figure : m_selectedFigures) {
			compoundFigure->Add(figure);
			std::vector<CFigureMovementDecorator*>::iterator itShapes = find(m_figures.begin(), m_figures.end(), figure);
			if (itShapes != m_figures.end())
				m_figures.erase(itShapes);
		}
		m_selectedFigures.clear();
		m_indexMovableFigure = -1;
		m_figures.push_back(compoundFigure);
	}
}

void CFiguresHandler::UngroupFigures() {
	if (m_selectedFigures.size() == 1 && static_cast<CFigureComposite*>(m_selectedFigures.front())) {
		SaveHistory();
		CFigureComposite* compoundFigure = dynamic_cast<CFigureComposite*>(m_selectedFigures.front());
		std::vector<CFigureMovementDecorator*> figures = compoundFigure->GetFigures();

		std::vector<CFigureMovementDecorator*>::iterator itShapes = find(m_figures.begin(), m_figures.end(), compoundFigure);
		if (itShapes != m_figures.end())
			m_figures.erase(itShapes);
		for (CFigureMovementDecorator* figure : figures) {
			m_figures.push_back(figure);
		}
		m_selectedFigures.clear();
		m_indexMovableFigure = -1;
	}
}

void CFiguresHandler::MoveFigure() {
	if (m_indexMovableFigure != -1 && m_figures[m_indexMovableFigure]->GetMoved()) {
		m_figures[m_indexMovableFigure]->SetPosition(m_cursorPosition.x - m_dX, m_cursorPosition.y - m_dY);
	}
}

void CFiguresHandler::Draw() {
	for (auto figure : m_figures) {
		figure->Draw(m_window);
	}
}

std::vector<CFigureMovementDecorator*> CFiguresHandler::GetFigures() const {
	return m_figures;
}

void CFiguresHandler::SaveHistory() {
	m_history.push(CFiguresMemento(CFeatures::GetNewFigures(m_figures), CFeatures::GetNewFigures(m_selectedFigures)));
}

void CFiguresHandler::UndoHistory() {
	if (m_history.size() > 0) {
		auto previousMemento = m_history.top();
		m_figures = previousMemento.GetFigures();
		m_selectedFigures = previousMemento.GetSelectedFigures();
		m_indexMovableFigure = -1;
		m_cursorPosition = Vector2i(0, 0);
		m_dX = 0;
		m_dY = 0;
		m_history.pop();
	}
}

void CFiguresHandler::ImportMemento(CFiguresMemento memento) {
	if (memento.GetFigures().size() != 0) {
		SaveHistory();
		m_figures = memento.GetFigures();
		m_selectedFigures = memento.GetSelectedFigures();
		m_indexMovableFigure = -1;
		m_cursorPosition = Vector2i(0, 0);
		m_dX = 0;
		m_dY = 0;
	}
}