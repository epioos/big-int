#ifndef BIG_INT_ZAHL_H
#define BIG_INT_ZAHL_H

#include <array>
#include "iostream"

class Zahl {
    public:
        Zahl();
        Zahl(unsigned int initial_value);

        friend std::ostream& operator<< (std::ostream& os, const Zahl& number_out);
        friend std::istream& operator>> (std::istream& is, Zahl& number_in);
        Zahl operator+ (const Zahl& right);
        Zahl operator- (unsigned int right);
        Zahl operator* (unsigned int right);
        bool operator== (const Zahl& right);
        bool operator!= (const Zahl& right);
        bool operator< (const Zahl& right);
        bool operator> (const Zahl& right);

        Zahl factorial();
    private:
        std::array<unsigned int,32> data_array;

};
#endif //BIG_INT_ZAHL_H
