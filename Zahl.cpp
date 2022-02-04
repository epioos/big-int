#include "Zahl.h"
#include <array>
#include <string>
#include <iomanip>
#include <algorithm>

Zahl::Zahl() {
    data_array.fill(0);
}


Zahl::Zahl(uint32_t initial_value) {
    data_array.fill(0);
    data_array[0] = initial_value;
}

/**
 * converting input to uint32_t - checks if number is to large
 */
uint32_t Zahl::to_long_int() {
    if (std::any_of(data_array.begin() + 1, data_array.end(), [](uint32_t check) {
        return check != 0;
    })) {
        std::cerr << "input number 2 is to large for this operation - calculation with: " << data_array[0] << std::endl;
    }

    return data_array[0];
}

/**
 * rendering dara_array as an hex number and write it to os
 */
std::ostream &operator<<(std::ostream &os, const Zahl &number_out) {
    bool first_digit = false;
    for (auto it = number_out.data_array.rbegin(); it != number_out.data_array.rend(); ++it) {
        if (!first_digit) {
            if (*it == 0) {
                continue;
            } else {
                first_digit = true;
            }
        }
        os << std::hex << std::setw(8) << std::setfill('0') << *it;
    }
    return os;
}

/**
 * reading the 1 [2] numbers of the input file
 */
std::istream &operator>>(std::istream &is, Zahl &user_in) {
    std::string string_to_convert;
    is >> string_to_convert;
    user_in = 0;
    for (char digit: string_to_convert) {
        if (isxdigit(digit)) {
            user_in = user_in * 16 + (std::stoul(std::string(1, digit), nullptr, 16));
        } else {
            throw std::runtime_error("Input string is not valid");
        }
    }
    return is;
}

/**
 * iterating over array which is stored in 'Zahl', addition on every part of the array and
 * add carry over to the next part of the array
 */
Zahl Zahl::operator+(const Zahl &user_input) {
    Zahl result;
    uint64_t part_result = 0;
    uint32_t carry_over = 0;
    for (unsigned int i = 0; i < data_array.size(); ++i) {
        part_result = static_cast<uint64_t>(data_array[i]) + user_input.data_array[i] + carry_over;
        carry_over = part_result >> 32;
        uint32_t value = part_result & 0xffffffff;
        result.data_array[i] = value;
    }
    return result;
}

Zahl Zahl::operator-(uint32_t user_input) {
    Zahl result = *this;
    if (*this < user_input) {
        throw std::runtime_error("output would be negative, type 'Zahl' does not support negative values");
    }
    result.data_array[0] -= user_input;
    return result;
}


/**
 * multiples every data_array with user_input and add carry over to the next data_array
 */
Zahl Zahl::operator*(uint32_t user_input) {
    Zahl result;
    uint64_t part_result;
    uint32_t carry_over = 0;
    for (unsigned int i = 0; i < data_array.size(); ++i) {
        part_result = static_cast<uint64_t>(data_array[i]) * user_input + carry_over;
        carry_over = part_result / UINT32_MAX;
        result.data_array[i] = part_result;
    }
    return result;
}

/**
 * compares every part of data_array an checks if all are the same
 */
bool Zahl::operator==(const Zahl &user_input) {
    for (unsigned int i = 0; i < data_array.size(); ++i) {
        if (data_array[i] != user_input.data_array[i]) {
            return false;
        }
    }
    return true;
}

bool Zahl::operator!=(const Zahl &user_input) {
    return !(*this == user_input);
}

/**
 * compares every part of data_array - starting at the highest part
 */
bool Zahl::operator<(const Zahl &user_input) {
    for (int32_t i = data_array.size() - 1; i >= 0; --i) {
        if (data_array[i] == user_input.data_array[i]) {
            continue;
        } else if (data_array[i] < user_input.data_array[i]) {
            return true;
        } else {
            return false;
        }
    }
    return false;
}

bool Zahl::operator>(const Zahl &user_input) {
    return !(*this < user_input) && (*this != user_input);
}


Zahl Zahl::factorial() {
    if (*this > 170) {
        throw std::runtime_error("Output number would be to large for this datatype, please input a number <= 170");
    }
    Zahl result = 1;
    if (data_array[0] > 1) {
        for (uint32_t i = 1; *this > i || *this == i; ++i) {
            result = result * i;
        }
    }
    return result;
}