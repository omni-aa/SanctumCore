# Create SanctumCore library
add_library(SanctumCore
        core/Person.cpp
        utils/Logger.cpp
)

# Apply standard settings
apply_standard_settings(SanctumCore)

# Include directories for the library
target_include_directories(SanctumCore PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)