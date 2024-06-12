add_executable()

add_custom_target(
    driver_compile
    ALL
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    COMMAND gcc ${my_cflags} ${CMAKE_CURRENT_SOURCE_DIR}/atkbd.c -o ${CMAKE_CURRENT_BINARY_DIR}/atkbd.o
    COMMAND gcc ${my_cflags} ${CMAKE_CURRENT_SOURCE_DIR}/vesa.c -o ${CMAKE_CURRENT_BINARY_DIR}/vesa.o
    COMMENT "编译driver"
)
