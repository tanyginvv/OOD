#include "CTriangleBuilder.h"

CTriangleBuilder::CTriangleBuilder(std::vector<unsigned int> characteristics)
	:m_point0({ static_cast<float>(characteristics[0]),
		static_cast<float>(characteristics[1]) }),
	m_point1({ static_cast<float>(characteristics[2]),
		static_cast<float>(characteristics[3]) }),
	m_point2({ static_cast<float>(characteristics[4]),
		static_cast<float>(characteristics[5]) }),
	m_position({ static_cast<float>(characteristics[6]),
		static_cast<float>(characteristics[7]) })
{
	m_fillColor = characteristics[8];
	m_outlineColor = characteristics[9];
	m_outlineThickness = characteristics[10];
}

void CTriangleBuilder::SetShape() {
	auto triangleShape = new ConvexShape();
	triangleShape->setPointCount(3);
	triangleShape->setPoint(0, m_point0);
	triangleShape->setPoint(1, m_point1);
	triangleShape->setPoint(2, m_point2);
	m_figure = new CTriangleDecorator(triangleShape);
}

void CTriangleBuilder::SetPosition() {
	m_figure->SetPosition(m_position.x, m_position.y);
}