add_custom_target(
    mm_compile
    ALL
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMAND gcc ${my_cflags} ${CMAKE_CURRENT_SOURCE_DIR}/malloc.c -o ${CMAKE_CURRENT_BINARY_DIR}/malloc.o
    COMMAND gcc ${my_cflags} ${CMAKE_CURRENT_SOURCE_DIR}/memory.c -o ${CMAKE_CURRENT_BINARY_DIR}/memory.o
    COMMAND gcc ${my_cflags} ${CMAKE_CURRENT_SOURCE_DIR}/page_alloc.c -o ${CMAKE_CURRENT_BINARY_DIR}/page_alloc.o
    COMMENT "编译mm"
)
