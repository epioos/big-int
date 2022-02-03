#include <iostream>
#include <fstream>
#include "Zahl.h"

/*
 * reading an operator from file and executing the operator on that given number(s)
 */

int main() {
    std::ifstream input_file;
    input_file.open("../test_cases/test8.txt", std::ifstream::in);
    if (!input_file.is_open()) {
        std::cerr << "Could not open the input file";
        return -1;
    }
    std::string in_operator;
    Zahl zahl_one;
    Zahl zahl_two;
    input_file >> in_operator;
    try {
        input_file >> zahl_one;
        input_file >> zahl_two;
        input_file.close();
    } catch (const std::runtime_error &input_error) {
        std::cerr << input_error.what() << std::endl;
        input_file.close();
        return -1;
    }

    Zahl result;
    switch (in_operator[0]) {
        case '+':
            result = zahl_one + zahl_two;
            break;
        case '-':
            try {
                result = zahl_one - zahl_two.to_long_int();
            } catch (const std::runtime_error &substraction_error) {
                std::cerr << substraction_error.what() << std::endl;
            }

            break;
        case '*':
            result = zahl_one * zahl_two.to_long_int();
            break;
        case 'f':
            try {
                result = zahl_one.factorial();
            } catch (const std::runtime_error &factorial_error) {
                std::cerr << factorial_error.what() << std::endl;
            }

            break;
        default:
            std::cerr << "this operator is not supported" << std::endl;
    }
    std::cout << "Result: " << result << std::endl;
    return 0;
}