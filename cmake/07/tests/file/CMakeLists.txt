project(file_test)

add_executable(${PROJECT_NAME} tester.c)

target_include_directories(${PROJECT_NAME} PUBLIC ${test_extra_include_dirs})