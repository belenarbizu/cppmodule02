#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->_n = 0;
}

Fixed::Fixed(const int n)
{

}

Fixed::Fixed(const float n)
{
    
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
    this->_n = f.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_n;
}

void Fixed::setRawBits(int const raw)
{
    this->_n = raw;
}

float Fixed::toFloat(void) const
{

}

int Fixed::toInt(void) const
{

}