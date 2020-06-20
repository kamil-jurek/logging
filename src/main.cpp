#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <map>

#include "Bond.hpp"

int main(int argc, char *argv[]) {

   std::cout << "Hello World!\n" << std::endl;
   
   Bond bond_1;

   int a = 1;
   double b = 2.0;
   float c = 3.0;
   std::string d = "st_ri_ng";
   std::vector<int> e = {1,2,3,4};
   std::map<std::string, int> f = {{"one", 1}, {"two", 2}};
   std::array<int, 3> g = {7, 8, 9};

   kj::print(std::cout, "a", a,
                        "b", b,
                        "c", c);
   
   kj::print(std::cout, "d", d);
   kj::print(std::cout, "e", e);
   kj::print(std::cout, "f", f);
   kj::print(std::cout, "g", g);

   kj::print(std::cout, "bond_1", bond_1);

   return 0;
}
