#include <iostream>
#include "Investment.hpp"

Investment::Investment() : value{0}
{
    std::cout << "Investment constructor with value = " << value << "\n";
}

Investment::Investment(int value_) : value{value_}
{
    std::cout << "Investment(int value_) constructor with value_ = " << value_ << "\n";
}

Investment::Investment(const Investment& inv)
{
    value = inv.getValue();

    std::cout << "Investment(const Investment&) constructor with value = " << value << "\n";
} 

Investment::~Investment()
{
    std::cout << "Investment destructor\n";
}

int Investment::getValue() const
{
    return value;
}

