#include "CSaveBinaryFileStrategy.h"

void CSaveBinaryFileStrategy::Save(std::string filename, std::vector<CFigureMovementDecorator*> figures) {
    std::ofstream output(filename + ".bin",  std::ios::binary);

    std::size_t size = figures.size();
    output.write((char*)&size, sizeof(size));

    for (const auto& figure : figures) {
        output.write((char*)&figure, sizeof(figure));
    }

    output.close();
}
