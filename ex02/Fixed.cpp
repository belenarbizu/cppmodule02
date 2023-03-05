#include "Fixed.hpp"

Fixed::Fixed()
{
    this->_n = 0;
}

Fixed::Fixed(const int n)
{
    this->setRawBits(n << this->_bits);
}

Fixed::Fixed(const float n)
{
    this->setRawBits((int)roundf(n * (1 << this->_bits)));
}

Fixed::Fixed(const Fixed& f)
{
    *this = f;
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
    return this->_n;
}

void Fixed::setRawBits(int const raw)
{
    this->_n = raw;
}

float Fixed::toFloat(void) const
{
    return ((float)this->getRawBits() / (1 << this->_bits));
}

int Fixed::toInt(void) const
{
    return (this->getRawBits() >> this->_bits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& f)
{
    os << f.toFloat();
    return os;
}

bool Fixed::operator> (const Fixed& f)
{
    return this->getRawBits() > f.getRawBits();
}

bool Fixed::operator< (const Fixed& f)
{
    return this->getRawBits() < f.getRawBits();
}

bool Fixed::operator>= (const Fixed& f)
{
    return this->getRawBits() >= f.getRawBits();
}

bool Fixed::operator<= (const Fixed& f)
{
    return this->getRawBits() <= f.getRawBits();
}

bool Fixed::operator== (const Fixed& f)
{
    return this->getRawBits() == f.getRawBits();
}

bool Fixed::operator!= (const Fixed& f)
{
    return this->getRawBits() != f.getRawBits();
}

Fixed& Fixed::operator= (const Fixed& f)
{
    this->setRawBits(f.getRawBits());
    return *this;
}

Fixed Fixed::operator+ (const Fixed& f)
{
    return (Fixed(this->toFloat() + f.toFloat()));
}

Fixed Fixed::operator- (const Fixed& f)
{
    return (Fixed(this->toFloat() - f.toFloat()));
}

Fixed Fixed::operator* (const Fixed& f)
{
    return (Fixed(this->toFloat() * f.toFloat()));
}

Fixed Fixed::operator/ (const Fixed& f)
{
    return (Fixed(this->toFloat() / f.toFloat()));
}

Fixed& Fixed::operator++ (void)
{
    this->setRawBits(this->getRawBits() + 1);
    return *this;
}

Fixed& Fixed::operator-- (void)
{
    this->setRawBits(this->getRawBits() - 1);
    return *this;
}

Fixed Fixed::operator++ (int)
{
    Fixed temp = *this;
    operator++();
    return temp;
}

Fixed Fixed::operator-- (int)
{
    Fixed temp = *this;
    operator--();
    return temp;
}

Fixed& Fixed::min(Fixed &f, Fixed& f2)
{
    if (f.getRawBits() < f2.getRawBits())
        return f;
    return f2;
}

Fixed& Fixed::max(Fixed&f, Fixed& f2)
{
    if (f.getRawBits() > f2.getRawBits())
        return f;
    return f2;
}

const Fixed& Fixed::min(const Fixed& f, const Fixed& f2)
{
    if (f.getRawBits() < f2.getRawBits())
        return f;
    return f2;
}

const Fixed& Fixed::max(const Fixed& f, const Fixed& f2)
{
    if (f.getRawBits() > f2.getRawBits())
        return f;
    return f2;
}