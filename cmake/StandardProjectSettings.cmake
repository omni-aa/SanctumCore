# Set default build type to Release if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Set compiler warnings for specific targets
function(apply_standard_settings target_name)
    # Apply compiler warnings to the specific target
    set_project_warnings(${target_name})

    # Position independent code for shared libraries
    set_target_properties(${target_name} PROPERTIES
            POSITION_INDEPENDENT_CODE ON
    )

    # Set C++ standard for the target
    set_target_properties(${target_name} PROPERTIES
            CXX_STANDARD 17
            CXX_STANDARD_REQUIRED ON
    )
endfunction()