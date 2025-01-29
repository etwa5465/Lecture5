#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "functions_to_implement.cpp"

TEST_CASE("Split Function") {
    REQUIRE(Split("a,b,c", ",") == std::vector<std::string>{"a", "b", "c"});
    REQUIRE(Split("hello world", " ") == std::vector<std::string>{"hello", "world"});
    REQUIRE(Split("one|two|three", "|") == std::vector<std::string>{"one", "two", "three"});
}

TEST_CASE("Factorial Function") {
    REQUIRE(Factorial(0) == 1);
    REQUIRE(Factorial(1) == 1);
    REQUIRE(Factorial(5) == 120);
}

TEST_CASE("EvenMask Function") {
    REQUIRE(EvenMask({1, 2, 3, 4}) == std::vector<bool>{false, true, false, true});
    REQUIRE(EvenMask({10, 15, 20, 25}) == std::vector<bool>{true, false, true, false});
    REQUIRE(EvenMask({0, 7, 8, 9}) == std::vector<bool>{true, false, true, false});
}
