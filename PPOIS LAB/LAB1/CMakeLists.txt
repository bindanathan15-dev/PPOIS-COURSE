cmake_minimum_required(VERSION 3.14)

project(PPOIS_LAB1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Main laboratory application
add_executable(lab1
    main.cpp
    set.cpp
    "VECTOR 3D.cpp"
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

target_link_libraries(Vector3DTests
    PRIVATE GTest::gtest_main
)

# Set unit tests
add_executable(SetTests
    tests/SetTests.cpp
    set.cpp
)

target_link_libraries(SetTests
    PRIVATE GTest::gtest_main
)

# Register tests
include(GoogleTest)

gtest_discover_tests(Vector3DTests)
gtest_discover_tests(SetTests)
