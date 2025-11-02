#include <cassert>
#include <stdexcept>
#include <vector>
#include "sanctum/core/Calculator.h"

using namespace SanctumCore::core;

void test_calculator_basic_operations() {
    assert(Calculator::add(2.0, 3.0) == 5.0);
    assert(Calculator::subtract(5.0, 3.0) == 2.0);
    assert(Calculator::multiply(4.0, 5.0) == 20.0);
    assert(Calculator::divide(10.0, 2.0) == 5.0);
}

void test_calculator_advanced_operations() {
    // Test division by zero
    try {
        SanctumCore::core::Calculator::divide(5.0, 0.0);
        assert(false && "Should have thrown exception");
    } catch (const std::invalid_argument&) {
        // Expected
    }

    // Test average calculation
    std::vector<double> numbers = {1.0, 2.0, 3.0, 4.0, 5.0};
    assert(Calculator::calculateAverage(numbers) == 3.0);

    // Test empty vector average
    try {
        std::vector<double> empty;
        Calculator::calculateAverage(empty);
        assert(false && "Should have thrown exception");
    } catch (const std::invalid_argument&) {
        // Expected
    }
}