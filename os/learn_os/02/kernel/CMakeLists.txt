add_custom_target(
    kernel_compile
    ALL
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMAND gcc ${my_cflags} ${CMAKE_CURRENT_SOURCE_DIR}/interrupt.c -o ${CMAKE_CURRENT_BINARY_DIR}/interrupt.o
    COMMAND gcc ${my_cflags} ${CMAKE_CURRENT_SOURCE_DIR}/sched.c -o ${CMAKE_CURRENT_BINARY_DIR}/sched.o
    COMMAND gcc ${my_cflags} ${CMAKE_CURRENT_SOURCE_DIR}/syscall.c -o ${CMAKE_CURRENT_BINARY_DIR}/syscall.o
    COMMAND gcc ${my_cflags} ${CMAKE_CURRENT_SOURCE_DIR}/tss.c -o ${CMAKE_CURRENT_BINARY_DIR}/tss.o
    COMMENT "编译kernel"
)
