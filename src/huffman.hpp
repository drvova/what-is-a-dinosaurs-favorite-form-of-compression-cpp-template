#pragma once
#include <string>
#include <unordered_map>
#include <queue>

struct Z {
    char x;
    int y;
    Z* a;
    Z* b;
    Z(char c, int n) : x(c), y(n), a(nullptr), b(nullptr) {}
    Z(int n) : x(0), y(n), a(nullptr), b(nullptr) {}
};

struct Q {
    bool operator()(Z* u, Z* v) { return u->y > v->y; }
};

struct R {
    std::unordered_map<char, std::string> m;
    std::unordered_map<char, int> k;
    std::string d;
};

std::unordered_map<char, int> c(const std::string& s);
Z* t(const std::unordered_map<char, int>& f);
void g(Z* r, std::string w, std::unordered_map<char, std::string>& m);
R p(const std::string& s);
std::string q(const std::string& d, const std::unordered_map<char, std::string>& m);
void e(Z* r);
int factorial(int n);