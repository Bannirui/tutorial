add_custom_target(
    ipc_compile
    ALL
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMAND gcc ${my_cflags} ${CMAKE_CURRENT_SOURCE_DIR}/shm.c -o ${CMAKE_CURRENT_BINARY_DIR}/shm.o
    COMMENT "编译ipc"
)
