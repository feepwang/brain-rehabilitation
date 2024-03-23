add_executable(fibo fibonacci.cpp)
target_link_libraries(fibo PRIVATE br GTest::gtest_main)
gtest_discover_tests(fibo)
