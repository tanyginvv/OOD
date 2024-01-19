#include "CApplication.h"
#include <fstream>
#include <iostream>
#include <vector>

const std::string outputFileName = "output.txt";

int main()
{
	std::ifstream input("input.txt");
	std::ofstream output(outputFileName);

	RenderWindow window(sf::VideoMode(1500, 1000), "Shapes");
	window.setVerticalSyncEnabled(true);

	CApplication* application = CApplication::GetInstance(input, output, window);
	application->ReadFigures();

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event))
		{
			application->ProcessAnEvent(event);
		}
	}

	application->PrintFiguresInfo();

	input.close();
	output.close();

	return 0;
}