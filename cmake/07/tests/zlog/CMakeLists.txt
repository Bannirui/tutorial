project(zlog_test)

add_executable(${PROJECT_NAME} tester.c)

target_include_directories(${PROJECT_NAME} PUBLIC ${test_extra_include_dirs})
target_link_directories(${PROJECT_NAME} PUBLIC ${test_extra_lib_dirs})
target_link_libraries(${PROJECT_NAME} zlog)

add_test(NAME "zlog_test"
        COMMAND "zlog_test"
        arg1
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
