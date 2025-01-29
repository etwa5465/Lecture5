#ifndef CATCH_HPP
#define CATCH_HPP

#include <iostream>
#include <vector>
#include <string>
#include <functional>

#define CATCH_CONFIG_MAIN

struct TestCase {
    std::string name;
    std::function<void()> func;
};

class CatchFramework {
public:
    static CatchFramework& getInstance() {
        static CatchFramework instance;
        return instance;
    }

    void addTest(const std::string& name, std::function<void()> func) {
        tests.push_back({name, func});
    }

    void run() {
        int passed = 0;
        int total = tests.size();
        for (const auto& test : tests) {
            try {
                test.func();
                std::cout << "[PASS] " << test.name << "\n";
                passed++;
            } catch (const std::exception& e) {
                std::cout << "[FAIL] " << test.name << " - " << e.what() << "\n";
            }
        }
        std::cout << "\n" << passed << "/" << total << " tests passed.\n";
    }

private:
    std::vector<TestCase> tests;
};

#define TEST_CASE(name) \
    void name(); \
    struct name##_Register { \
        name##_Register() { CatchFramework::getInstance().addTest(#name, name); } \
    } name##_register; \
    void name()

#define REQUIRE(cond) if (!(cond)) throw std::runtime_error("Requirement failed: " #cond);

#endif // CATCH_HPP
