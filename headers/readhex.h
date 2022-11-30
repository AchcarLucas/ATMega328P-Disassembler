#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>

class FileException : public std::exception {
    private:
        std::string message;
    public:
        FileException(std::string msg) : message(msg) {}
        std::string what () {
            return message;
        }
};

union U
{
    unsigned int value;
    unsigned short hex;
};

std::vector<unsigned short> * readHexFile(std::string file_name);
