#include "CCircleBuilder.h"

CCircleBuilder::CCircleBuilder(std::vector<unsigned int> characteristics)
	:m_center({ static_cast<float>(characteristics[0]),
		static_cast<float>(characteristics[1]) }),
	m_radius(characteristics[2])
{
	m_fillColor = characteristics[3];
	m_outlineColor = characteristics[4];
	m_outlineThickness = characteristics[5];
}

void CCircleBuilder::SetShape() {
	m_figure = new CCircleDecorator(new CircleShape(m_radius));
}

void CCircleBuilder::SetPosition() {
	m_figure->SetPosition(m_center.x - m_radius, m_center.y - m_radius);
}