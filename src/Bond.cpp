#include <iostream>
#include "Bond.hpp"

Bond::Bond() : Investment{}, name{"empty"}
{
    std::cout << "\t Bond constructor with value = " << value << "\n";
}

Bond::Bond(int value_) : Investment{value_}, name{"empty"}
{
    std::cout << "\t Bond(int value_) constructor with value_ = " << value_ << "\n";
}

Bond::Bond(const Bond& bond)
{
    value = bond.getValue();
    std::cout << "\t Bond(const Bond&) constructor with value = " << value << "\n";
}

Bond::Bond(Bond&& bond)
{
    value = bond.getValue();
    std::cout << "\t Bond(const Bond&&) constructor with value = " << value << "\n";
}

Bond::~Bond()
{
     std::cout << "\t Bond destructor\n";
}

void Bond::printData(std::ostream& os) const {
    os << "{\n";
    kj::print(os, 
              "value", value,
              "name", name);
    os << "}";
}