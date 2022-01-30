#ifndef BIG_INT_ZAHL_H
#define BIG_INT_ZAHL_H

#include <array>
#include "iostream"

class Zahl {
    public:
        Zahl();
        Zahl(uint32_t initial_value);

        friend std::ostream& operator<< (std::ostream& os, const Zahl& number_out);
        friend std::istream& operator>> (std::istream& is, Zahl& number_in);
        Zahl operator+ (const Zahl& right);
        Zahl operator- (uint32_t right);
        Zahl operator* (uint32_t right);
        bool operator== (const Zahl& right);
        bool operator!= (const Zahl& right);
        bool operator< (const Zahl& right);
        bool operator> (const Zahl& right);

        Zahl factorial();
    private:
        std::array<uint32_t,32> data_array;

};
#endif //BIG_INT_ZAHL_H
