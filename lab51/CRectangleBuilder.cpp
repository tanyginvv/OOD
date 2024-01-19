#include "CRectangleBuilder.h"

CRectangleBuilder::CRectangleBuilder(std::vector<unsigned int> characteristics)
	:m_pointLT({ static_cast<float>(characteristics[0]),
		static_cast<float>(characteristics[1]) }),
	m_pointRB({ static_cast<float>(characteristics[2]),
		static_cast<float>(characteristics[3]) })
{
	m_fillColor = characteristics[4];
	m_outlineColor = characteristics[5];
	m_outlineThickness = characteristics[6];
}

void CRectangleBuilder::SetShape() {
	m_figure = new CRectangleDecorator(new RectangleShape({ abs(m_pointRB.x - m_pointLT.x), abs(m_pointRB.y - m_pointLT.y) }));
}

void CRectangleBuilder::SetPosition() {
	m_figure->SetPosition(m_pointLT.x, m_pointLT.y);
}