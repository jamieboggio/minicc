cmake_minimum_required(VERSION 3.23)

project(
  minicc
  VERSION 0.1.0
  DESCRIPTION "My personal attempt at a small C Compiler"
  HOMEPAGE_URL "https://github.com/jamieboggio/minicc"
  LANGUAGES C
)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# ---- Declare executable ----

add_executable(minicc_exe src/main.c
  src/lexer.c
  src/ds.c)
add_executable(minicc::exe ALIAS minicc_exe)

set_property(TARGET minicc_exe PROPERTY OUTPUT_NAME minicc)

target_compile_features(minicc_exe PRIVATE c_std_17)

target_include_directories(
  minicc_exe PRIVATE
  "${PROJECT_SOURCE_DIR}/include"
)
