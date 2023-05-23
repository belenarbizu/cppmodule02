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

    bool operator> (const Fixed& f);
    bool operator< (const Fixed& f);
    bool operator>= (const Fixed& f);
    bool operator<= (const Fixed& f);
    bool operator== (const Fixed& f);
    bool operator!= (const Fixed& f);

    Fixed& operator= (const Fixed& f);
    Fixed operator+ (const Fixed& f);
    Fixed operator- (const Fixed& f);
    Fixed operator* (const Fixed& f);
    Fixed operator/ (const Fixed& f);

    Fixed& operator++ (void);
    Fixed& operator-- (void);
    Fixed operator++ (int);
    Fixed operator-- (int);

    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;

    static Fixed& min(Fixed& f, Fixed& f2);
    static Fixed& max(Fixed& f, Fixed& f2);
    static const Fixed& min(const Fixed& f, const Fixed& f2);
    static const Fixed& max(const Fixed& f, const Fixed& f2);
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);

#endif