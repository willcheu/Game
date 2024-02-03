cmake_minimum_required(VERSION 3.10)

include(FetchContent)

project(Game)

set(CMAKE_CXX_STANDARD 17)

set(SFML_VERSION "2.6.1")

FetchContent_Declare(
        sfml
        GIT_REPOSITORY "https://github.com/SFML/SFML.git"
        GIT_TAG        "${SFML_VERSION}"
)

FetchContent_GetProperties(sfml)
if(NOT sfml_POPULATED)
    FetchContent_Populate(sfml)
    add_subdirectory(${sfml_SOURCE_DIR} ${sfml_BINARY_DIR})
endif()

set(SOURCE
        main.cpp
)

add_executable(2DComputerGraphicsApp
        ${SOURCE}
)

target_link_libraries(2DComputerGraphicsApp
        PRIVATE
        sfml-audio
        sfml-graphics
        sfml-system
        sfml-window
)

target_compile_options(2DComputerGraphicsApp PRIVATE -Wall)