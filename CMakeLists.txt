cmake_minimum_required(VERSION 3.10)
project(LibraryManagementSystem)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(LibraryManagementSystem src/Main.cpp src/Book.cpp src/Member.cpp src/Library.cpp)

add_custom_target(run
    COMMAND LibraryManagementSystem
    DEPENDS LibraryManagementSystem
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
