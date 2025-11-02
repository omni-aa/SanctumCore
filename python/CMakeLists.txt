# Create Python bindings module
pybind11_add_module(SanctumPython
        bindings.cpp
)

# Apply standard settings to Python module
apply_standard_settings(SanctumPython)

# Link core library to Python module
target_link_libraries(SanctumPython PRIVATE SanctumCore)

# Include directories for Python module
target_include_directories(SanctumPython PRIVATE
        ${CMAKE_SOURCE_DIR}/include
)

# Set output directory for Python module
set_target_properties(SanctumPython PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/python
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/python
)

# Copy required DLLs to output directory (WINDOWS ONLY)
if(WIN32)
    # Find the MinGW bin directory
    get_filename_component(MINGW_BIN_DIR ${CMAKE_CXX_COMPILER} DIRECTORY)

    # List of required DLLs
    set(REQUIRED_DLLS
            "libgcc_s_seh-1.dll"
            "libstdc++-6.dll"
            "libwinpthread-1.dll"
    )

    # Copy each DLL to output directory
    foreach(DLL ${REQUIRED_DLLS})
        add_custom_command(TARGET SanctumPython POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${MINGW_BIN_DIR}/${DLL}"
                "${CMAKE_BINARY_DIR}/python/${DLL}"
                COMMENT "Copying ${DLL} to output directory"
        )
    endforeach()
endif()