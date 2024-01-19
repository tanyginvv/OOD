#include "CImportTextFileTemplate.h"

CFiguresMemento CImportTextFileTemplate::Import(std::string filename) {
	std::ifstream input(filename + ".txt");

	return CFiguresMemento(GetFiguresFromFile(input), {});
}