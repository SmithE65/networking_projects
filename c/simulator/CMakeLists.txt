add_library(${SIMULATOR_LIB} STATIC
        graph.c
        graph.h
        net.c
        net.h
        node.h interface.c interface.h node.c link.h)

target_include_directories(${SIMULATOR_LIB} PUBLIC
        "./"
        )

target_link_libraries(${SIMULATOR_LIB} PUBLIC
        ${COMMON_LIB}
        )