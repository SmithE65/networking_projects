set(LIBRARY_SOURCES
    "linkedlist.c"
)
set(LIBRARY_INCLUDES
    "./"
)

add_library(${COMMON_LIB} STATIC
    ${LIBRARY_SOURCES}
    ${LIBRARY_HEADERS}
)

target_include_directories(${COMMON_LIB} PUBLIC
    ${LIBRARY_HEADERS}
)