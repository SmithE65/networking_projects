

add_subdirectory(${COMMON_LIB})
add_subdirectory(${SIMULATOR_LIB})

add_executable(${TESTAPP} testapp.c
    util.c
    topologies.c
)

target_link_libraries(${TESTAPP} PUBLIC
        ${COMMON_LIB}
        ${SIMULATOR_LIB}
        )

if (MSVC)
    # warning level 4
    add_compile_options(/W4)
else()
    # additional warnings
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()
