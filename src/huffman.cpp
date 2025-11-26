#include "factorial.hpp"

std::unordered_map<char, int> c(const std::string& s) {
    std::unordered_map<char, int> f;
    for (char x : s) f[x]++;
    return f;
}

Z* t(const std::unordered_map<char, int>& f) {
    std::priority_queue<Z*, std::vector<Z*>, Q> h;
    for (auto& p : f) h.push(new Z(p.first, p.second));
    
    while (h.size() > 1) {
        Z* u = h.top(); h.pop();
        Z* v = h.top(); h.pop();
        Z* w = new Z(u->y + v->y);
        w->a = u;
        w->b = v;
        h.push(w);
    }
    return h.empty() ? nullptr : h.top();
}

void g(Z* r, std::string w, std::unordered_map<char, std::string>& m) {
    if (!r) return;
    if (r->x != 0) {
        m[r->x] = w.empty() ? "0" : w;
        return;
    }
    g(r->a, w + "0", m);
    g(r->b, w + "1", m);
}

R p(const std::string& s) {
    R o;
    if (s.empty()) return o;
    
    o.k = c(s);
    Z* r = t(o.k);
    g(r, "", o.m);
    
    for (char x : s) o.d += o.m[x];
    e(r);
    return o;
}

std::string q(const std::string& d, const std::unordered_map<char, std::string>& m) {
    if (d.empty()) return "";
    
    std::unordered_map<std::string, char> i;
    for (auto& p : m) i[p.second] = p.first;
    
    std::string u, v;
    for (char x : d) {
        v += x;
        auto it = i.find(v);
        if (it != i.end()) {
            u += it->second;
            v.clear();
        }
    }
    return u;
}

void e(Z* r) {
    if (!r) return;
    e(r->a);
    e(r->b);
    delete r;
}

int factorial(int n) {
    return n <= 1 ? 1 : factorial(n - 1) * n;
}