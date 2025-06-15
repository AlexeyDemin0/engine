cmake_minimum_required(VERSION 3.26)
project(Engine)

# required to generate compile_commands.json for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

# cpp standard setup
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# disable extensions gnu++17
set(CMAKE_CXX_EXTENSIONS OFF)

option(ENABLE_TESTS "Build and run tests" ON)

add_subdirectory(src)

if (ENABLE_TESTS)
  include(FetchContent)
  FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.17.0
  )
  FetchContent_MakeAvailable(googletest)

  enable_testing()

  add_subdirectory(tests)
endif()
