#pragma once

#include "CBuilder.h"
#include "CRectangleDecorator.h"

class CRectangleBuilder : public CBuider {
public:
	CRectangleBuilder(std::vector<unsigned int> characteristics);
	void SetShape() override;
	void SetPosition() override;
private:
	Vector2f m_pointLT;
	Vector2f m_pointRB;
};