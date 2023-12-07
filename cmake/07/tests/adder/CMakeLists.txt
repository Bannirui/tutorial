project(adder_test)

add_executable(${PROJECT_NAME} tester.c)

target_include_directories(${PROJECT_NAME} PUBLIC ${test_extra_include_dirs})
target_link_directories(${PROJECT_NAME} PUBLIC ${test_extra_lib_dirs})
target_link_libraries(${PROJECT_NAME} Adder)

add_test(NAME "adder_test"
        COMMAND "adder_test"
        arg1
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
