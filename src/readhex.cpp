#include "../headers/readhex.h"

std::vector<unsigned short> * readHexFile(std::string file_name) {
    std::vector<unsigned short> * bin = new std::vector<unsigned short>();
    std::cout << "Open file " << file_name << std::endl;
    std::fstream file;
    file.open(file_name, std::ios::in);
    if(!file) throw FileException("Invalid open file exception " + file_name);
    std::string hex = "0000";
    unsigned int index = 0;
    file.ignore(9);
    U u;
    /*
    * unpacking hex file to bin
    */
    while (true) {
        if((index % 9) != 0) {
            file >> hex[3];
            file >> hex[2];
            file >> hex[0];
            file >> hex[1];
            std::stringstream SS(hex);
            SS >> std::hex >> u.value;
            bin->insert(bin->end(), u.hex);
            if (file.eof())
                break;
        }
        if((++index % 9) == 0)
            file.ignore(12);
    }

    file.close();
    return bin;
}
