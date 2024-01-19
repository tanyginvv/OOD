#include "CSaveFileStrategy.h"

std::string CSaveFileStrategy::GetCircleInfo(CCircleDecorator* circleDecorator) {
	auto circleShape = circleDecorator->GetCircle();

	auto position = circleShape->getPosition();
	auto radius = circleShape->getRadius();
	Vector2f center = { position.x + radius, position.y + radius };
	auto outlineThickness = circleShape->getOutlineThickness();
	auto fillColor = circleShape->getFillColor();
	auto outlineColor = circleShape->getOutlineColor();

	std::stringstream stream;

	stream << circle << " " << center.x << " "
		<< center.y << " " << static_cast<int>(radius) << " "
		<< fillColor.toInteger() << " " << outlineColor.toInteger()
		<< " " << static_cast<int>(outlineThickness) << std::endl;

	return stream.str();
}

std::string CSaveFileStrategy::GetRectangleInfo(CRectangleDecorator* rectangleDecorator) {
	auto rectangleShape = rectangleDecorator->GetRectangle();
	auto rectangleBounds = rectangleDecorator->GetGlobalBounds();

	auto pointLT = rectangleShape->getPosition();
	auto outlineThickness = rectangleShape->getOutlineThickness();
	Vector2f pointRB = {
		(pointLT.x + rectangleBounds.width - 2 * outlineThickness),
		(pointLT.y + rectangleBounds.height - 2 * outlineThickness) };
	auto fillColor = rectangleShape->getFillColor();
	auto outlineColor = rectangleShape->getOutlineColor();

	std::stringstream stream;

	stream << rectangle << " " << pointLT.x << " "
		<< pointLT.y << " " << pointRB.x << " " << pointRB.y << " "
		<< fillColor.toInteger() << " " << outlineColor.toInteger()
		<< " " << static_cast<int>(outlineThickness) << std::endl;

	return stream.str();
}

std::string CSaveFileStrategy::GetTriangleInfo(CTriangleDecorator* triangleDecorator) {
	auto triangleShape = triangleDecorator->GetTriangle();

	auto point0 = triangleShape->getPoint(0);
	auto point1 = triangleShape->getPoint(1);
	auto point2 = triangleShape->getPoint(2);
	auto position = triangleShape->getPosition();
	auto fillColor = triangleShape->getFillColor();
	auto outlineColor = triangleShape->getOutlineColor();
	auto outlineThickness = triangleShape->getOutlineThickness();

	std::stringstream stream;

	stream << triangle << " "
		<< point0.x << " " << point0.y << " "
		<< point1.x << " " << point1.y << " "
		<< point2.x << " " << point2.y << " "
		<< position.x << " " << position.y << " "
		<< fillColor.toInteger() << " " << outlineColor.toInteger()
		<< " " << static_cast<int>(outlineThickness) << std::endl;

	return stream.str();
}

void CSaveFileStrategy::WriteFiguresInfo(std::ostream& output, std::vector<CFigureMovementDecorator*> figures) {
	for (auto figure : figures) {
		if (typeid(*figure) == typeid(CCircleDecorator)) {
			output << GetCircleInfo(static_cast<CCircleDecorator*>(figure));
		}
		else if (typeid(*figure) == typeid(CRectangleDecorator)) {
			output << GetRectangleInfo(static_cast<CRectangleDecorator*>(figure));
		}
		else if (typeid(*figure) == typeid(CTriangleDecorator)) {
			output << GetTriangleInfo(static_cast<CTriangleDecorator*>(figure));
		}
		else if (typeid(*figure) == typeid(CFigureComposite)) {
			output << grouped << std::endl;
			WriteFiguresInfo(output, static_cast<CFigureComposite*>(figure)->GetFigures());
			output << endGrouped << std::endl;
		}
	}
	//for (const auto& figure : figures) {
	//	// «апись данных фигуры в бинарный поток
	//	output.write(reinterpret_cast<const char*>(&figure), sizeof(CFigureMovementDecorator));
	//}
}
