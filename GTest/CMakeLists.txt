# 04-GTest/CMakeLists.txt
enable_testing()

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

target_include_directories(LibraryManagementSystem PRIVATE ../include)

add_executable(
    GTestExample
    hello_test.cpp
    ../src/Book.cpp
    ../src/Member.cpp
    ../src/Library.cpp
)
target_link_libraries(
    GTestExample
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(GTestExample)

# Register the test with CTest
add_test(NAME GTestExample COMMAND GTestExample)