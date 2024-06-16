# 编译和汇编 不链接
add_custom_target(
        as_kernel
        ALL
        COMMAND gcc ${my_include} -c ${CMAKE_CURRENT_SOURCE_DIR}/handler.S -o handler.o
        COMMENT "汇编kernel"
)
