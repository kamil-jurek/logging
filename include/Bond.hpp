#pragma once

#include <string>

#include "Investment.hpp"
#include "Printable.hpp"

class Bond : public Investment, public Printable
{
  public:
    Bond();
    Bond(int value_);
    Bond(const Bond&);
    Bond(Bond&&);
    
    void printData(std::ostream&) const;

    ~Bond();

  private:
    std::string name;
};