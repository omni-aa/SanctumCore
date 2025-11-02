cmake_minimum_required(VERSION 3.20)

# Download pybind11 automatically
include(FetchContent)
FetchContent_Declare(
        pybind11
        GIT_REPOSITORY https://github.com/pybind/pybind11.git
        GIT_TAG v2.11.1
)

project(SanctumCore VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Project options
option(BUILD_TESTS "Build tests" ON)
option(BUILD_APPS "Build applications" ON)
option(BUILD_PYTHON_BINDINGS "Build Python bindings using pybind11" ON)

# Make pybind11 available only if Python bindings are enabled
if(BUILD_PYTHON_BINDINGS)
    FetchContent_MakeAvailable(pybind11)
    message(STATUS "Python bindings enabled: pybind11 configured")
endif()

# Include CMake modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(CompilerWarnings)
include(StandardProjectSettings)

# Set output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add subdirectories
add_subdirectory(src)

# Add applications if enabled
if(BUILD_APPS)
    add_subdirectory(apps)
endif()

# Add Python bindings subdirectory if enabled
if(BUILD_PYTHON_BINDINGS)
    add_subdirectory(python)
endif()

# Add tests if enabled
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

# Install targets
install(DIRECTORY include/ DESTINATION include)
install(TARGETS SanctumCore
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        RUNTIME DESTINATION bin
)