cmake_minimum_required(VERSION 3.25)

project(main VERSION 1.2.4)

#[[
模拟lib的查找过程
实际上当前项目的库并没有install
所以即使find library没有结果也不影响后续的编译
]]
find_library(myzloglib
        PATHS "/usr/local/lib"
        NAMES zlog zlog.1
        DOC "zlog library")

if (${myzloglib} STREQUAL "myzloglib-NOTFOUND")
    # 实际项目中找不到依赖库直接FATAL不要继续流程了
    # message(FATAL_ERROR "no zlog!")
    message(WARNING "no zlog!")
else ()
    list(APPEND extra_include_dirs "/usr/local/include")
    list(APPEND extra_lib_dirs "/usr/local/lib")
    list(APPEND extra_links ${myzloglib})
    message(STATUS "zlog founded, as ${myzloglib}")
endif ()

#[[
开关控制adder模块
-控制是否要编译模块
-是否使用该模块编译出来的库
]]
option(USE_ADDER "A simple library for adding 2 integer." ON)
if (USE_ADDER)
    # 模块编译
    add_subdirectory(Adder)
    # 记录这个库的头文件目录 库文件目录 库文件名称
    # 供下面指定扫描头文件路径 库文件路径和链接的库名称
    list(APPEND extra_include_dirs "${PROJECT_SOURCE_DIR}/Adder/include")
    list(APPEND extra_lib_dirs "${CMAKE_CURRENT_BINARY_DIR}/Adder")
    list(APPEND extra_links adder)
endif ()

#[[
文件生成
在.h.in文件中用@@包裹的占位符会用cmake中定义的变量填充
上面project已经定义了项目名和版本号
在.h.in中@main_VERSION_MAJOR@便是读取main这个项目的major版本号
]]
configure_file(TestConfig.h.in TestConfig.h)

add_executable(${PROJECT_NAME} main.c)

# .h.in生成的.h文件加到头文件目录 便可以在源码中引用头文件
target_include_directories(${PROJECT_NAME}
        PUBLIC ${PROJECT_BINARY_DIR})

# DOWNLOAD ALL THE SUBMODULES
find_package(Git QUIET)
if (GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
    # UPDATE SUBMODULES AS NEEDED
    option(git_submodule "Check submodules during build ON")
    if (git_submodule)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                RESULT_VARIABLE git_submodule_result)
        if (NOT git_submodule_result EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${git_submodule_result}, pls check submodules.")
        endif ()
    endif ()
endif ()

# CHECK ALL THE SUBMODULES
if (NOT EXISTS "${PROJECT_SOURCE_DIR}/external/zlog/CMakeLists.txt")
    message(FATAL_ERROR "The zlog submodules was not downloaded! ${git_submodule} wa turned off or failed. pls check.")
endif ()

#[[
在sub directory之前确保git module
]]
add_subdirectory(external/zlog)

#[[
头文件目录
-三方库 源码目录/external/zlog/src
-模块化的头文件
]]
target_include_directories(${PROJECT_NAME}
        PUBLIC external/zlog/src
        ${extra_include_dirs}
)

#[[
库文件目录
用PUBLIC开放依赖的传递性
-三方库build/external/zlog/lib/libzlog.a
-模块化的库文件目录
]]
target_link_directories(${PROJECT_NAME}
        PUBLIC external/zlog/lib
        ${extra_lib_dirs}
)

#[[
链接库的名字
-三方库libzlog.a
-模块化的库名称
]]
target_link_libraries(${PROJECT_NAME}
        zlog
        ${extra_links}
)

# 可执行程序install到/usr/local/bin中
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
# 头文件install到/usr/local/include中
install(FILES "${PROJECT_BINARY_DIR}/TestConfig.h" DESTINATION include)

#[[
cpack打包
]]
# 指定包的版本号 就用上面project()指令设置好的项目版本信息
set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})
# 打包内容包含该平台任何运行时库
include(InstallRequiredSystemLibraries)
# 正常项目目录下都会有license
set(cpack_resource_file_license "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
# cpack是cmake内置功能 include(CPack)启用该功能
include(CPack)

# ctest
option(TEST_FILE "test configure_file" ON)
option(TEST_ADDER "test lib: adder" ON)
option(TEST_ZLOG "test lib: zlog" ON)

if (TEST_FILE)
    list(APPEND test_extra_include_dirs "${PROJECT_BINARY_DIR}")
endif ()
#[[
因为上面模拟了一个开关USE_ADDER
此时需要一个开关TEST_ADDER
二者一定不能同时为TRUE 否则会导致Adder被两次add_subdirectory 会报错
]]
if (TEST_ADDER)
    add_subdirectory(Adder)
    list(APPEND test_extra_include_dirs "${PROJECT_SOURCE_DIR}/Adder/include")
    list(APPEND test_extra_lib_dirs "${CMAKE_CURRENT_BINARY_DIR}/Adder")
    list(APPEND test_extra_links adder)
endif ()
if (TEST_ZLOG)
    list(APPEND test_extra_include_dirs "${CMAKE_CURRENT_SOURCE_DIR}/external/zlog/src")
    list(APPEND test_extra_lib_dirs "${CMAKE_CURRENT_BINARY_DIR}/external/zlog/lib")
    list(APPEND test_extra_links zlog)
endif ()

if (TEST_FILE OR TEST_ADDER OR TEST_ZLOG)
    add_subdirectory(tests)
endif ()