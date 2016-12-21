cmake_minimum_required(VERSION 2.8)

project(c__at)

include_directories("include")

# Main sources.
set(SOURCES
    src/cpu.c
    src/log.c
)

# Be explicit about C standard (and C++ for unittest).
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98")

# Be obnoxious about warnings (but not pedantic).
add_compile_options(-Wall -Wextra)

# Create the standard binary.
add_executable(c__at main.c ${SOURCES})

# Test sources.
set(UT_SOURCES
    unittests/Flags_tTests.cpp
    unittests/Registers_tTests.cpp
)

# Create the unittest binary.
add_executable(c__at_tests utmain.cpp ${UT_SOURCES} ${SOURCES})
target_link_libraries(c__at_tests CppUTest CppUTestExt)

# Enable the tests to be run via make.
enable_testing()
add_test(c__at_tests c__at_tests -r2 -c -v)
