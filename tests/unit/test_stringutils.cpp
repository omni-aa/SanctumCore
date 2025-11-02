#include <cassert>
#include <vector>
#include "sanctum/core/StringUtils.h"

using namespace SanctumCore::core;

void test_string_utils_basic() {
    assert(StringUtils::toUpperCase("hello") == "HELLO");
    assert(StringUtils::toLowerCase("HELLO") == "hello");
    assert(StringUtils::trim("  test  ") == "test");
    assert(StringUtils::trim("test") == "test");
    assert(StringUtils::trim("   ") == "");
}

void test_string_utils_advanced() {
    // Test split functionality
    auto result = StringUtils::split("a,b,c", ',');
    assert(result.size() == 3);
    assert(result[0] == "a");
    assert(result[1] == "b");
    assert(result[2] == "c");

    // Test split with no delimiter
    auto result2 = StringUtils::split("abc", ',');
    assert(result2.size() == 1);
    assert(result2[0] == "abc");
}