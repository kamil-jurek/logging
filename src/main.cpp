#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <map>

#include "Bond.hpp"

int main(int argc, char *argv[]) {

   std::cout << "Hello World!\n" << std::endl;
   
   Bond bond_1;

   int int_val = 1;
   double double_val = 2.0;
   float float_val = 3.0;
   std::string str_val = "st_ri_ng";
   std::vector<int> vec_val = {1,2,3,4};
   std::map<std::string, int> map_val = {{"one", 1}, {"two", 2}};
   std::array<int, 3> arr_val = {7, 8, 9};
   std::pair<int, std::vector<std::string> > pair_val = {10, {"one", "two", "three"}};
   std::vector<std::pair<int, Bond> > pair_vec = {{11, Bond{11}}, {12, Bond{12}}, {13, Bond{13}}};

   print(std::cout, "int_val", int_val,
                    "double_val", double_val,
                    "float_val", float_val);
   
   printNl(std::cout, "str_val", str_val);
   printNl(std::cout, "evec_val", vec_val);
   printNl(std::cout, "map_val", map_val);
   printNl(std::cout, "arr_val", arr_val);
   printNl(std::cout, "pair_val", pair_val);

   printNl(std::cout, "bond_1", bond_1);

   printNl(std::cout, "pair_vec", pair_vec);

   return 0;
}
