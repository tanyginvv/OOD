#include "CApplication.h"

CApplication::CApplication(std::istream& input, std::ostream& output, RenderWindow& window)
	:m_input(input),
	m_output(output),
	m_window(window)
{
	m_figuresHandler = new CFiguresHandler(m_window);
	m_toolbar = new CToolbar(new CDragAndDropState(), m_window, m_figuresHandler);
	m_fileHandler = new CFileHandler("savedFile", m_figuresHandler, new CSaveTextFileStrategy(), new CImportTextFileTemplate());
}

CApplication* CApplication::m_instance = nullptr;

CApplication* CApplication::GetInstance(std::istream& input, std::ostream& output, RenderWindow& window) {
	if (m_instance == nullptr) {
		m_instance = new CApplication(input, output, window);
	}

	return m_instance;
}

void CApplication::ReadFigures() {
	std::string line;
	std::stringstream ss;

	while (getline(m_input, line)) {
		ss.clear();
		ss.str(line);
		m_figuresHandler->CreatingFigures(ss);
	}
}

void CApplication::DrawApplication() {
	m_figuresHandler->Draw();
	m_toolbar->Draw();
}

void CApplication::ProcessAnEvent(Event event) {
	m_figuresHandler->SetCursorPosition(Mouse::getPosition(m_window));
	m_toolbar->SetCursorPosition(Mouse::getPosition(m_window));

	switch (event.type)
	{
	case Event::Closed:
		m_window.close();
		break;
	case Event::MouseButtonPressed:
		if (Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
			if (event.type == Event::MouseButtonPressed)
				if (event.key.code == Mouse::Left)
					if (typeid(*m_toolbar->GetState()) == typeid(CDragAndDropState))
						m_figuresHandler->SelectFigures();
		}
		else if (event.type == Event::MouseButtonPressed) {
			if (event.key.code == Mouse::Left) {
				if (m_toolbar->PressToolButton())
					m_figuresHandler->UnselectFigures();
				if (typeid(*m_toolbar->GetState()) == typeid(CDragAndDropState))
					m_figuresHandler->SelectFigure();
				else if (typeid(*m_toolbar->GetState()) == typeid(CFillState))
					m_figuresHandler->Accept(new CFillVisitor(m_toolbar->GetSelectedColor()));
				else if (typeid(*m_toolbar->GetState()) == typeid(CFillOutlineState))
					m_figuresHandler->Accept(new CFillOutlineVisitor(m_toolbar->GetSelectedColor()));
				else if (typeid(*m_toolbar->GetState()) == typeid(CChangeOutlineThicknessState))
					m_figuresHandler->Accept(new CChangeOutlineThicknessVisitor(m_toolbar->GetSelectedThickness()));
			}

			if (event.key.code == Mouse::Right)
				if (typeid(*m_toolbar->GetState()) == typeid(CDragAndDropState))
					m_figuresHandler->UnselectFigure();
		}

		break;
	case Event::MouseButtonReleased:
		if (event.key.code == Mouse::Left)
			if (typeid(*m_toolbar->GetState()) == typeid(CDragAndDropState))
				m_figuresHandler->ResetTheIndexMovableFigure();
		break;
	case Event::KeyPressed:
		if (Keyboard::isKeyPressed(sf::Keyboard::LControl)) {

			if (Keyboard::isKeyPressed(sf::Keyboard::G)) {
				m_figuresHandler->GroupFigures();
			}

			if (Keyboard::isKeyPressed(sf::Keyboard::U)) {
				m_figuresHandler->UngroupFigures();
			}
			if (Keyboard::isKeyPressed(sf::Keyboard::Z)) {
				m_figuresHandler->UndoHistory();
			}

			if (Keyboard::isKeyPressed(Keyboard::S)) {

				if (Keyboard::isKeyPressed(Keyboard::T)) {
					if (m_fileHandler->GetTypeSaveFileStrategy() != typeid(CSaveTextFileStrategy).name()) {
						m_fileHandler->SetSaveFileStrategy(new CSaveTextFileStrategy());
					}
					m_fileHandler->Save();
				}

				if (Keyboard::isKeyPressed(Keyboard::B)) {
					if (m_fileHandler->GetTypeSaveFileStrategy() != typeid(CSaveBinaryFileStrategy).name()) {
						m_fileHandler->SetSaveFileStrategy(new CSaveBinaryFileStrategy());
					}
					m_fileHandler->Save();
				}

			}

			if (Keyboard::isKeyPressed(Keyboard::I)) {

				if (Keyboard::isKeyPressed(Keyboard::T)) {
					if (m_fileHandler->GetTypeImportFileStrategy() != typeid(CImportTextFileTemplate).name()) {
						m_fileHandler->SetImportFileStrategy(new CImportTextFileTemplate());
					}
					m_figuresHandler->ImportMemento(m_fileHandler->Import());
				}

				if (Keyboard::isKeyPressed(Keyboard::B)) {
					if (m_fileHandler->GetTypeImportFileStrategy() != typeid(CImportBinaryFileTemplate).name()) {
						m_fileHandler->SetImportFileStrategy(new CImportBinaryFileTemplate());
					}
					m_figuresHandler->ImportMemento(m_fileHandler->Import());
				}
			}
		}
		break;
	}

	if (typeid(*m_toolbar->GetState()) == typeid(CDragAndDropState))
		m_figuresHandler->MoveFigure();

	Render();
}

void CApplication::Render() {
	m_window.clear();
	DrawApplication();
	m_window.display();
}

void CApplication::PrintFiguresInfo() {
	auto figures = m_figuresHandler->GetFigures();

	for (auto figure : figures) {
		m_output << figure->GetDescription() << std::endl;
	}
}