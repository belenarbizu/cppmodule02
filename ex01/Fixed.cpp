#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->_n = 0;
}

Fixed::Fixed(const int n)
{
    std::cout << "Int constructor called" << std::endl;
    this->setRawBits(n << this->_bits); // n * 2^8
}

Fixed::Fixed(const float n)
{
    std::cout << "Float constructor called" << std::endl;
    this->setRawBits((int)roundf(n * (1 << this->_bits))); //n * 256
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& f)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = f;
}

Fixed& Fixed::operator= (const Fixed& f)
{
    std::cout << "Assignation operator called" << std::endl;
    setRawBits(f.getRawBits());
    return *this;
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
    return ((float)this->getRawBits() / (1 << this->_bits)); //n entre 256
}

int Fixed::toInt(void) const
{
    return (this->getRawBits() >> this->_bits); //n entre 2^8
}

std::ostream& operator<<(std::ostream& os, const Fixed& f)
{
    os << f.toFloat();
    return os;
}