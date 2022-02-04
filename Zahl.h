#ifndef BIG_INT_ZAHL_H
#define BIG_INT_ZAHL_H

#include <array>
#include "iostream"

/**
 * @brief datatype representing 32x bigger int then uint32_t
 */
class Zahl {
public:
    /**
     * @brief initial datatype 'Zahl' as empty array
     */
    Zahl();

    /**
     * @brief initial datatype 'Zahl' with an uint32_t at data_array[0]
     * @param initial_value uint32_t input value
     */
    Zahl(uint32_t initial_value);

    /**
     * Overload of the std::cout - rights the number to and output stream (console) - in hex
     * @param os stream to output to
     * @param number_out number to output
     * @return ostream -> modified ostream
     */
    friend std::ostream &operator<<(std::ostream &os, const Zahl &number_out);

    /**
     * Overload of the std::cin - reads inputs from an instream (file) - in hex
     * @param is input stream to read from
     * @param user_in the operator or number the user puts in
     * @return istream -> modified instream
     */
    friend std::istream &operator>>(std::istream &is, Zahl &user_in);

    /**
     * @brief addition of two numbers of datatype 'Zahl'
     * @param user_input number to add
     * @return 'Zahl' -> result of addition
     */
    Zahl operator+(const Zahl &user_input);

    /**
     * @brief subtract an uint32_t from a number of datatype 'Zahl'
     * @param user_input number to subtract
     * @return 'Zahl' -> result of subtraction
     */
    Zahl operator-(uint32_t user_input);

    /**
     * @brief multiples a number of datatype 'Zahl' with an uint32_t
     * @param user_input number to multiply with
     * @return 'Zahl' -> result of multiplication
     */
    Zahl operator*(uint32_t user_input);

    /**
     * @brief compares two numbers of datatype 'Zahl' if they are equal
     * @param user_input number to compare with
     * @return bool -> true if two 'Zahl' are equal, false if they are not equal
     */
    bool operator==(const Zahl &user_input);

    /**
     * @brief compares two number of datatype 'Zahl' if they are equal not equal
     * @param user_input number to compare with
     * @return bool -> true if two 'Zahl' are not equal, false if they are equal
     */
    bool operator!=(const Zahl &user_input);

    /**
     * @brief checks if 'Zahl' is less then other 'Zahl'
     * @param user_input number to compare with
     * @return bool -> true if 'Zahl' is less than other 'Zahl', false if not
     */
    bool operator<(const Zahl &user_input);

    /**
     * @brief checks  if 'Zahl' is greater than other 'Zahl'
     * @param user_input number to compare with
     * @return bool -> true if 'Zahl' is greater than other 'Zahl', false if not
     */
    bool operator>(const Zahl &user_input);

    uint32_t to_long_int();

    /**
     * @brief calculate the factorial of 'Zahl'
     * The maximum of 'Zahl' is 170 in this function otherwise the factorial
     * could not be calculated correctly and will overflow
     * @return 'Zahl' -> the factorial of your 'Zahl'
     */
    Zahl factorial();

private:
    /**
     * declares an array of 32x unint32_t
     */
    std::array<uint32_t, 32> data_array;
};

#endif //BIG_INT_ZAHL_H
