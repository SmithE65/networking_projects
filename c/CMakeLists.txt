

add_subdirectory(${COMMON_LIB})

add_executable(${TESTAPP} testapp.c
    graph.c
    topologies.c
)

target_link_libraries(${TESTAPP} PUBLIC ${COMMON_LIB})
