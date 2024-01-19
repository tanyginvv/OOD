#include "CSaveTextFileStrategy.h"

void CSaveTextFileStrategy::Save(std::string filename, std::vector<CFigureMovementDecorator*> figures) {
	std::ofstream output(filename + ".txt");
	WriteFiguresInfo(output, figures);
	output.close();
}