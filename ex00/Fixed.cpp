#include "Fixed.hpp"

Fixed::Fixed()
{
    this->n = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& f)
{
    this->n = f.n;
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator= (const Fixed&)
{
    std::cout << "Assignation operator called" << std::endl;
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->n;
}

void Fixed::setRawBits(int const raw)
{
    this->n = raw;
}