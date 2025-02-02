cmake_minimum_required(VERSION 3.10)
project(ChessEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(${PROJECT_SOURCE_DIR}/include)


# Enable testing
enable_testing()

# Find GTest package
find_package(GTest REQUIRED)

# Add source files
add_library(chess_lib 
    src/move_generator.cpp
)

# Create test executable
add_executable(run_tests tests/move_generator_test.cpp)

target_include_directories(chess_lib PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(run_tests
    PRIVATE
        chess_lib
        GTest::GTest
        GTest::Main
)

# Add test to CTest
add_test(NAME ChessTests COMMAND run_tests)