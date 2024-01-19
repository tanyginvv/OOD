#pragma once

#include "CBuilder.h"
#include "CTriangleDecorator.h"

class CTriangleBuilder : public CBuider {
public:
	CTriangleBuilder(std::vector<unsigned int> characteristics);
	void SetShape() override;
	void SetPosition() override;
private:
	Vector2f m_point0;
	Vector2f m_point1;
	Vector2f m_point2;
	Vector2f m_position;
};