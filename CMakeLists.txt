cmake_minimum_required(VERSION 2.8)

project(c__at)

include_directories("include")

set(SOURCES
    main.c
    src/log.c
)

add_compile_options(-std=c99 -Wall -Wextra)

add_executable(c__at ${SOURCES})
