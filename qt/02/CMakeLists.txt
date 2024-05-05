cmake_minimum_required(VERSION 3.5)

project(02 VERSION 0.1 LANGUAGES CXX)

# ui compiler
set(CMAKE_AUTOUIC ON)
# meta object compiler
set(CMAKE_AUTOMOC ON)
# resource compiler
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "/home/dingrui/MyApp/Qt/6.7.0/gcc_64")
find_package(Qt6 REQUIRED COMPONENTS Widgets)

aux_source_directory(. PROJECT_SOURCES)

qt_add_executable(02
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
    resource.qrc
)

target_link_libraries(02 PRIVATE Qt6::Widgets)

set_target_properties(02 PROPERTIES
        ${BUNDLE_ID_OPTION}
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
)