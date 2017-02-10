cmake_minimum_required(VERSION 2.8)

project(c__at)

include_directories("${CMAKE_SOURCE_DIR}/include")

# Main sources.
set(SOURCES
    ${CMAKE_SOURCE_DIR}/src/cpu.c
    ${CMAKE_SOURCE_DIR}/src/log.c
    ${CMAKE_SOURCE_DIR}/src/memory.c
)

# Be explicit about C standard (and C++ for unittest).
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")

# Be obnoxious about warnings (but not pedantic).
add_compile_options(-Wall -Wextra)

# Create the standard binary.
add_executable(c__at main.c ${SOURCES})

# Configure the unit tests.
enable_testing()
add_subdirectory(unittests)