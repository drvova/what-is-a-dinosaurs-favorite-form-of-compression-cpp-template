#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include "../src/factorial.hpp"

TEST_CASE("f") {
    REQUIRE(factorial(0) == 1);
    REQUIRE(factorial(5) == 120);
}

TEST_CASE("c1") {
    std::string s = "aabbc";
    auto f = c(s);
    REQUIRE(f['a'] == 2);
    REQUIRE(f['b'] == 2);
    REQUIRE(f['c'] == 1);
}

TEST_CASE("c2") {
    auto f = c("");
    REQUIRE(f.empty());
}

TEST_CASE("c3") {
    auto f = c("x");
    REQUIRE(f['x'] == 1);
    REQUIRE(f.size() == 1);
}

TEST_CASE("p1") {
    std::string s = "aabbc";
    auto r = p(s);
    REQUIRE_FALSE(r.m.empty());
    REQUIRE_FALSE(r.k.empty());
    REQUIRE_FALSE(r.d.empty());
    REQUIRE(r.k['a'] == 2);
    REQUIRE(r.k['b'] == 2);
    REQUIRE(r.k['c'] == 1);
}

TEST_CASE("p2") {
    auto r = p("");
    REQUIRE(r.m.empty());
    REQUIRE(r.k.empty());
    REQUIRE(r.d.empty());
}

TEST_CASE("p3") {
    auto r = p("xxxx");
    REQUIRE(r.m.size() == 1);
    REQUIRE(r.m['x'] == "0");
    REQUIRE(r.d == "0000");
}

TEST_CASE("q1") {
    std::string s = "abc";
    auto r = p(s);
    auto d = q(r.d, r.m);
    REQUIRE(s == d);
}

TEST_CASE("q2") {
    std::string d = "";
    std::unordered_map<char, std::string> m;
    auto x = q(d, m);
    REQUIRE(x.empty());
}

TEST_CASE("q3") {
    std::string s = "x";
    auto r = p(s);
    auto d = q(r.d, r.m);
    REQUIRE(s == d);
}

TEST_CASE("pref") {
    std::string s = "abc";
    auto r = p(s);
    for (auto it1 = r.m.begin(); it1 != r.m.end(); ++it1) {
        for (auto it2 = it1; it2 != r.m.end(); ++it2) {
            if (it1 != it2) {
                REQUIRE_FALSE(it1->second.find(it2->second) == 0);
                REQUIRE_FALSE(it2->second.find(it1->second) == 0);
            }
        }
    }
}

TEST_CASE("space") {
    std::string s = "xxxxxxxxxxxxxxxxxxxx";
    auto r = p(s);
    REQUIRE(r.d.length() < s.length() * 8);
}

TEST_CASE("rt") {
    std::vector<std::string> t = {
        "abc",
        "xyz",
        "xxxxxyyyyzzzz",
        "",
        "a",
        "xyz"
    };
    for (auto& s : t) {
        auto r = p(s);
        auto d = q(r.d, r.m);
        REQUIRE(s == d);
    }
}

TEST_CASE("b") {
    std::string s = "abcxyzabcxyz";
    BENCHMARK("p") { return p(s); };
    auto r = p(s);
    BENCHMARK("q") { return q(r.d, r.m); };
}