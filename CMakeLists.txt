cmake_minimum_required(VERSION 2.8.10)
project(console_hangman C)

set(CMAKE_C_STANDARD 11)

file(GLOB SOURCES "*.c")

add_executable(console_hangman ${SOURCES})
