function(set_project_warnings target_name)
    set(MSVC_WARNINGS
            /W4
            /w14242
            /w14287
            /w14296
            /w14311
            /w14826
            /w44062
            /w44242
            /w14905
            /w14906
    )

    set(CLANG_WARNINGS
            -Wall
            -Wextra
            -Wpedantic
            -Wconversion
            -Wshadow
            -Wnon-virtual-dtor
            -Wold-style-cast
            -Wcast-align
            -Wunused
            -Woverloaded-virtual
    )

    set(GCC_WARNINGS
            -Wall
            -Wextra
            -Wpedantic
            -Wconversion
            -Wshadow
            -Wnon-virtual-dtor
            -Wold-style-cast
            -Wcast-align
            -Wunused
            -Woverloaded-virtual
    )

    if(MSVC)
        set(PROJECT_WARNINGS ${MSVC_WARNINGS})
    elseif(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
        set(PROJECT_WARNINGS ${CLANG_WARNINGS})
    elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        set(PROJECT_WARNINGS ${GCC_WARNINGS})
    else()
        message(AUTHOR_WARNING "No compiler warnings set for '${CMAKE_CXX_COMPILER_ID}' compiler.")
    endif()

    if(PROJECT_WARNINGS)
        target_compile_options(${target_name} PRIVATE ${PROJECT_WARNINGS})
    endif()
endfunction()