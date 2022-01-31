#include "Zahl.h"
#include <array>
#include <string>
#include <vector>
#include <iomanip>

Zahl::Zahl() {
    data_array.fill(0);
}


Zahl::Zahl(uint32_t initial_value) {
    data_array.fill(0);
    data_array[0] = initial_value;
}

std::ostream &operator<<(std::ostream &os, const Zahl &number_out) {
    for (auto it = number_out.data_array.rbegin(); it != number_out.data_array.rend(); ++it) {
        os << std::hex << std::setw(8) << std::setfill('0') << *it;
    }
    return os;
}

std::istream &operator>>(std::istream &is, Zahl &number_in) {
    std::string string_to_convert;
    is >> string_to_convert;
    number_in = 0;
    for (char digit: string_to_convert) {
        if (isdigit(digit)) {
            number_in = number_in * 10 + (digit - '0');
        } else {
            throw std::runtime_error("Input string is not valid");
        }
    }
    std::cout << "string_to_array: " << string_to_convert << std::endl;
    return is;
}

Zahl Zahl::operator+(const Zahl &right) {
    Zahl result;
    uint64_t part_result;
    uint32_t carry_over = 0;
    for (int i = 0; i < data_array.size(); ++i) {
        part_result = static_cast<uint64_t>(data_array[i]) + right.data_array[i] + carry_over;
        carry_over = part_result / UINT32_MAX;
        uint32_t value = part_result % UINT32_MAX;
        result.data_array[i] = value;
    }
    return result;
}

Zahl Zahl::operator-(uint32_t right) {
    if (*this < right) {
        throw std::runtime_error("output be negative, type 'Zahl' does not support negative values");
    }
    Zahl result = data_array[0] - right;

    return result;
}

Zahl Zahl::operator*(uint32_t right) {
    Zahl result;
    uint64_t part_result;
    uint32_t carry_over = 0;
    for (int i = 0; i < data_array.size(); ++i) {
        part_result = static_cast<uint64_t>(data_array[i]) * right + carry_over;
        carry_over = part_result / UINT32_MAX;
        result.data_array[i] = part_result;
    }
    return result;
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
    for (int32_t i = data_array.size() - 1; i >= 0; --i) {
        if (data_array[i] == right.data_array[i]) {
            continue;
        } else if (data_array[i] < right.data_array[i]) {
            return true;
        } else {
            return false;
        }
    }
    return false;
}

bool Zahl::operator>(const Zahl &right) {
    return !(*this < right) && (*this != right);
}


Zahl Zahl::factorial() {
    // 170 ist max
    Zahl result = 1;
    if (data_array[0] > 1){
        for (uint32_t i = 1; *this > i || *this == i; ++i) {
            result = result * i;
        }
    }
    return result;
}

uint32_t Zahl::to_long_int() {
    return data_array[0];
}








