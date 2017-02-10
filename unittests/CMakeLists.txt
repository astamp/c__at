# Test sources.
set(UT_SOURCES
    Flags_tTests.cpp
    MemoryTests.cpp
    Registers_tTests.cpp
)

# Configure the C++ standard for unittests.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98")

# Configure the memory leak detector macros.
# TODO: Don't hard code this path.
set(CPPUTEST_HOME /usr/local)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -include ${CPPUTEST_HOME}/include/CppUTest/MemoryLeakDetectorMallocMacros.h")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -include ${CPPUTEST_HOME}/include/CppUTest/MemoryLeakDetectorNewMacros.h")

# Create the unittest binary.
add_executable(c__at_tests utmain.cpp ${UT_SOURCES} ${SOURCES})
target_link_libraries(c__at_tests CppUTest CppUTestExt)

# Enable the tests to be run via make.
add_test(c__at_tests c__at_tests -r2 -c -v)
