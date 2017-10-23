cmake_minimum_required(VERSION 3.8)
project(untitled)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)

find_package(Boost)
IF (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
    add_executable(untitled ${SOURCE_FILES})
    target_link_libraries (untitled ${Boost_LIBRARIES})
endif()