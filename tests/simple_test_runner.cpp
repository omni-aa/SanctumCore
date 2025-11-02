#include <iostream>
#include <cassert>

// Declare test functions from other files
void test_calculator_basic_operations();
void test_calculator_advanced_operations();
void test_string_utils_basic();
void test_string_utils_advanced();

// Test counter
int tests_passed = 0;
int tests_failed = 0;

#define RUN_TEST(test_function) \
    try { \
        test_function(); \
        std::cout << "✓ " << #test_function << " passed" << std::endl; \
        tests_passed++; \
    } catch (const std::exception& e) { \
        std::cout << "✗ " << #test_function << " failed: " << e.what() << std::endl; \
        tests_failed++; \
    } catch (...) { \
        std::cout << "✗ " << #test_function << " failed with unknown exception" << std::endl; \
        tests_failed++; \
    }

int main() {
    std::cout << "=========================================" << std::endl;
    std::cout << "Running SanctumCore Test Suite" << std::endl;
    std::cout << "=========================================" << std::endl;

    // Run all test groups
    RUN_TEST(test_calculator_basic_operations);
    RUN_TEST(test_calculator_advanced_operations);
    RUN_TEST(test_string_utils_basic);
    RUN_TEST(test_string_utils_advanced);

    // Summary
    std::cout << "=========================================" << std::endl;
    std::cout << "Test Summary:" << std::endl;
    std::cout << "✓ Passed: " << tests_passed << std::endl;
    std::cout << "✗ Failed: " << tests_failed << std::endl;
    std::cout << "Total: " << (tests_passed + tests_failed) << std::endl;

    if (tests_failed == 0) {
        std::cout << "🎉 All tests passed!" << std::endl;
        return 0;
    } else {
        std::cout << "❌ Some tests failed!" << std::endl;
        return 1;
    }
}