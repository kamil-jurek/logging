#include <iostream>
#include <string>
#include <vector>
#include <map>

///#include "Printable.hpp"
#include "Bond.hpp"


// template <typename T>
// std::ostream& dump(const T& t, const std::string& name, std::ostream& stream) {
//    stream << name << " = " << t << '\n';

//    return stream;
// }

// template <typename T>
// void dump(const std::vector<T>& t, const std::string& name) {
//    std::cout << name << " = { ";
//    for (const T& e : t) {
//       std::cout << e << ", ";
//    }
//    std::cout << "}\n";
// }

// template <typename T1, typename T2>
// void dump(const std::map<T1, T2>& t, const std::string& name) {
//    std::cout << name << " = { ";
//    for (const auto& kv : t) {
//       std::cout << "[" << kv.first << "]" << ":" << kv.second << ", ";
//    }
//    std::cout << "}\n";
// }

int main(int argc, char *argv[]) {

   std::cout << "Hello World!\n" << std::endl;
   
   Bond bond_1;

   int a = 1;
   double b = 2.0;
   float c = 3.0;
   std::string d = "st_ri_ng";
   std::vector<int> e = {1,2,3,4};
   std::map<std::string, int> f = {{"one", 1}, {"two", 2}};

   kj::print(std::cout, "a", a,
                        "b", b,
                        "c", c);
   
   kj::print(std::cout, "d", d);
   kj::print(std::cout, "e", e);
   kj::print(std::cout, "f", f);
  
   kj::print(std::cout, "bond_1", bond_1);

   return 0;
}
