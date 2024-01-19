#pragma once

#include "CBuilder.h"
#include "CCircleDecorator.h"

class CCircleBuilder : public CBuider {
public:
	CCircleBuilder(std::vector<unsigned int> characteristics);
	void SetShape() override;
	void SetPosition() override;
private:
	Vector2f m_center;
	float m_radius;
};