cmake_minimum_required(VERSION 3.21)

include(cmake/prelude.cmake)

project(
  minicc
  VERSION 0.1.0
  DESCRIPTION "My personal attempt at a small C Compiler"
  HOMEPAGE_URL "https://github.com/jamieboggio/minicc"
  LANGUAGES C
)

include(cmake/variables.cmake)

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

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Developer mode ----

if(NOT minicc_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
    AUTHOR_WARNING
    "Developer mode is intended for developers of minicc"
  )
endif()

include(cmake/dev-mode.cmake)
