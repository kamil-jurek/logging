#pragma once

#include <iostream>
#include <vector>
#include <array>
#include <map>

class Printable {
  public:
    virtual ~Printable() = default;

    virtual void printData(std::ostream&) const {};
};

inline std::ostream& operator<<(std::ostream& os, const Printable& printable) {
    printable.printData(os);

    return os;
}

namespace kj {
    template <typename It>
    std::ostream& printRange(std::ostream& os, It beg, It end, size_t size) {
        os << '[' << size << "] {";
        for (auto it = beg; it != end; ++it) {
            if (it != beg) {
                os << ' ';
            }
            os << *it;
        }
        return os << '}';
    }

    template <typename T>
    std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
        return printRange(os, vec.begin(), vec.end(), vec.size());
    }

    template <typename T, size_t N>
    std::ostream& operator<<(std::ostream& os, const std::array<T, N>& arr) {
        return printRange(os, arr.begin(), arr.end(), arr.size());
    }

    template <typename T1, typename T2>
    std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& pair) {
        return os << "{" << pair.first << "," << pair.second << "}";
    }

    template <typename T1, typename T2>
    std::ostream& operator<<(std::ostream& os, const std::map<T1, T2>& map) {
        return printRange(os, map.begin(), map.end(), map.size());
    }

    template <typename T>
    void print(std::ostream& os, const T&) {}

    template <typename T>
    void print(std::ostream& os, const std::string& attrName, const T& attr) {
        os << attrName << " = " << attr << "\n";
    }

    template <typename Head, typename... Tail>
    void print(std::ostream& os, const std::string& attrName, const Head& head, Tail&&... tail) {
        kj::print(os, attrName, head);
        kj::print(os, tail...);
    }

} // kj

