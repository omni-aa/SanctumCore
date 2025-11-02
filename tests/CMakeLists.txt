if(BUILD_TESTS)
    # Simple test executable with all test files
    add_executable(SanctumCore_tests
            simple_test_runner.cpp
            unit/test_calculator.cpp
            unit/test_stringutils.cpp
            # Add this line
    )

    apply_standard_settings(SanctumCore_tests)

    # Link with main library AND include its directories
    target_link_libraries(SanctumCore_tests PRIVATE SanctumCore)

    # Add include directories for tests
    target_include_directories(SanctumCore_tests PRIVATE
            ${CMAKE_SOURCE_DIR}/include
    )

    # Add to CTest so CLion can discover tests
    add_test(NAME SanctumCore_All_Tests COMMAND SanctumCore_tests)

    message(STATUS "Tests enabled - modular test runner")
endif()