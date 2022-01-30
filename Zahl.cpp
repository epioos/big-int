//
// Created by tom-e on 28.01.2022.
//

#include "Zahl.h"
#include <array>
#include <string>
#include <vector>

Zahl::Zahl() {
    data_array.fill(0);
}


Zahl::Zahl(unsigned int initial_value) {
    data_array.fill(0);
    data_array[0] = initial_value;
}

std::ostream &operator<<(std::ostream &os, const Zahl &number_out) {
    return os;
}

std::istream &operator>>(std::istream &is, Zahl &number_in) {
    std::string string_to_convert;
    is >> string_to_convert;
    number_in = 0;
    for (char digit: string_to_convert) {
        if (isdigit(digit)) {
            number_in = number_in * 10 + digit - '0';
        } else {
            throw std::runtime_error("Input string is not valid");
        }
    }
    std::cout << "string_to_array: " << string_to_convert << std::endl;
    return is;
}

Zahl Zahl::operator+(const Zahl &right) {
    Zahl result;
    unsigned long int part_result;
    for (int i = 0; i < data_array.size(); ++i){
        part_result = data_array[i] + right.data_array[i];
        if(part_result > UINT32_MAX){

        }
    }
    return Zahl();
}

Zahl Zahl::operator-(unsigned int right) {
    return Zahl();
}

Zahl Zahl::operator*(unsigned int right) {
    return Zahl();
}

bool Zahl::operator==(const Zahl &right) {
    for (int i = 0; i < data_array.size(); ++i) {
        if (data_array[i] != right.data_array[i]) {
            return false;
        }
    }
    return true;
}

bool Zahl::operator!=(const Zahl &right) {
    return !(*this == right);
}

bool Zahl::operator<(const Zahl &right) {
    for (unsigned int i = data_array.size() - 1; i >= 0; --i) {
        if (data_array[i] == right.data_array[i]) {
            continue;
        } else if (data_array[i] < right.data_array[i]) {
            return true;
        } else{
            return false;
        }
    }
    return false;
}

bool Zahl::operator>(const Zahl &right) {
    return !(*this < right) && (*this != right);
}


Zahl Zahl::factorial() {
    return Zahl();
}











