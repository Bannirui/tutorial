enable_testing()

if (TEST_FILE)
    add_subdirectory(file)
endif ()

if (TEST_ADDER)
    add_subdirectory(adder)
    add_test(NAME "test1"
            COMMAND "adder_test"
            arg1
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
endif ()

if (TEST_ZLOG)
    add_subdirectory(zlog)
    add_test(NAME "test1"
            COMMAND "zlog_test"
            arg1
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
endif ()