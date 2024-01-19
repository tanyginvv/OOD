#include "CImportBinaryFileTemplate.h"

CFiguresMemento CImportBinaryFileTemplate::Import(std::string filename) {
    std::ifstream input(filename + ".txt", std::ios::binary);

    if (!input.is_open()) {
        throw std::runtime_error("Unable to open file for reading: " + filename);
    }

    std::size_t size;
    input.read((char*)&size, sizeof(size));

    std::vector<CFigureMovementDecorator*> figures;
    figures.resize(size);

    for (std::size_t i = 0; i < size; ++i) {
        input.read((char*)&figures[i], sizeof(figures[i]));
    }

    input.close();

    return CFiguresMemento(figures, {});
}

//CFiguresMemento CImportBinaryFileTemplate::Import(std::string filename) {
//    std::fstream input(filename + ".bin", std::ios::in | std::ios::out | std::ios::binary);
//    char ch[1];
//    std::string str = "";
//    while (input.read(ch, 1))
//        str += ch[0];
//
//    std::stringstream stream(str);
//
//    return CFiguresMemento(GetFiguresFromFile(stream), {});
//}
