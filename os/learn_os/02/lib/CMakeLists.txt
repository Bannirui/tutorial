add_custom_target(
    lib_compile
    ALL
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMAND gcc ${my_cflags} ${CMAKE_CURRENT_SOURCE_DIR}/string.c -o ${CMAKE_CURRENT_BINARY_DIR}/string.o
    COMMENT "编译lib"
)
