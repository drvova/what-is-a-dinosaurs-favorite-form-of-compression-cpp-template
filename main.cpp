#include <iostream>
#include "src/factorial.hpp"

int main() {
    std::string s = "abc";
    auto r = p(s);
    auto d = q(r.d, r.m);
    
    std::cout << "O: " << s << std::endl;
    std::cout << "C: " << r.d << std::endl;
    std::cout << "D: " << d << std::endl;
    std::cout << "M: " << (s == d ? "Y" : "N") << std::endl;
    
    return 0;
}