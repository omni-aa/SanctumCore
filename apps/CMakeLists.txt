# Create executable
add_executable(SanctumApp main.cpp)
apply_standard_settings(SanctumApp)

# Link library to executable
target_link_libraries(SanctumApp PRIVATE SanctumCore)

# ADD THIS: Include directories for the executable
target_include_directories(SanctumApp PRIVATE
        ${CMAKE_SOURCE_DIR}/include
)