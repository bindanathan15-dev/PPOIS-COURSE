cmake_minimum_required(VERSION 3.14)

project(PPOIS_LAB1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Main laboratory application
add_executable(lab1
    main.cpp
    set.cpp
    "VECTOR 3D.cpp"
)

target_include_directories(lab1
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
)

# Download GoogleTest
include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)

FetchContent_MakeAvailable(googletest)

# Enable testing
enable_testing()

# Vector3D unit tests
add_executable(Vector3DTests
    tests/Vector3DTests.cpp
    "VECTOR 3D.cpp"
)

target_include_directories(Vector3DTests
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(Vector3DTests
    PRIVATE GTest::gtest_main
)

# Set unit tests
add_executable(SetTests
    tests/setTests.cpp
    set.cpp
)

target_include_directories(SetTests
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(SetTests
    PRIVATE GTest::gtest_main
)

# Register tests
include(GoogleTest)

gtest_discover_tests(Vector3DTests)
gtest_discover_tests(SetTests)
# Enable code coverage for unit tests
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(Vector3DTests PRIVATE --coverage -O0 -g)
    target_link_options(Vector3DTests PRIVATE --coverage)

    target_compile_options(SetTests PRIVATE --coverage -O0 -g)
    target_link_options(SetTests PRIVATE --coverage)
endif()
