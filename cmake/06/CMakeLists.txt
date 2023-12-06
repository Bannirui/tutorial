cmake_minimum_required(VERSION 3.25)

project(main VERSION 1.2)

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

# 头文件目录
target_include_directories(${PROJECT_NAME}
        PUBLIC external/zlog/src
)

# 库文件目录
target_link_directories(${PROJECT_NAME}
        PRIVATE external/zlog/lib
)

# 链接库
# libzlog.a
target_link_libraries(${PROJECT_NAME}
        zlog
)