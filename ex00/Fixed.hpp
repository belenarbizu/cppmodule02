#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed
{
private:
    int n;
    static const int bits = 8;
public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed& f);
    Fixed& operator= (const Fixed&);
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif