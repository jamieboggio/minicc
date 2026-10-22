cmake_minimum_required(VERSION 3.24)

project(minicc LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(minicc
    src/main.cpp
    src/lexer.cpp
)

target_include_directories(minicc PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")
