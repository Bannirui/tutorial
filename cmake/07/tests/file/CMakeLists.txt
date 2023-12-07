project(file_test)

add_executable(${PROJECT_NAME} tester.c)

target_include_directories(${PROJECT_NAME} PUBLIC ${test_extra_include_dirs})

add_test(NAME "file_test"
        COMMAND "file_test"
        arg1
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
