#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int _n;
    static const int _bits = 8;
public:
    Fixed();
    Fixed(const int n);
    Fixed(const float n);
    ~Fixed();
    Fixed(const Fixed& f);
    Fixed& operator= (const Fixed& f);
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);

#endif