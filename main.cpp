#include <iostream>
#include <fstream>
#include "Zahl.h"

int main() {
    /*std::ifstream input_file;
    input_file.open("../input.txt", std::ifstream::in);
    if(!input_file.is_open()){
        std::cerr << "Could not open the input file";
        return -1;
    }
    std::string in_operator;
    Zahl zahl_one;
    Zahl zahl_two;
    input_file >> in_operator;
    std::cout << "In operator: "<< in_operator << std::endl;
    try{
        input_file >> zahl_one;
        input_file >> zahl_two;
        std::cout << "zahl_one: " << zahl_one << std::endl;
        std::cout << "zahl_two: " << zahl_two << std::endl;
        input_file.close();
    } catch (const std::runtime_error& input_error){
        std::cerr << input_error.what() << std::endl;
        input_file.close();
        return -1;
    }

    return 0;*/

    Zahl a = 3;
    unsigned long int b = 5;
    std::cout << a*b;

}
