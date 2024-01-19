#include "CImportFileTemplate.h"

std::vector<CFigureMovementDecorator*> CImportFileTemplate::GetFiguresFromFile(std::istream& input) {
	auto creator = CFiguresCreator();
	std::vector<unsigned int> characteristics;
	std::vector<CFigureMovementDecorator*> figures;
	std::string line, lineCharact, type;

	while ((input >> type) && std::getline(input, line)) {
		std::stringstream ss(line);
		while (ss >> lineCharact)
			characteristics.push_back(stoul(lineCharact));

		if (type == circle)
			creator.SetBuider(new CCircleBuilder(characteristics));
		else if (type == rectangle)
			creator.SetBuider(new CRectangleBuilder(characteristics));
		else if (type == triangle)
			creator.SetBuider(new CTriangleBuilder(characteristics));
		else if (type == grouped)
			creator.SetBuider(new CCompoundBuilder(GetFiguresFromFile(input)));
		else if (type == endGrouped)
			return figures;
		characteristics.clear();
		figures.push_back(creator.CreateAndGetFigure());
	}

	return figures;
}