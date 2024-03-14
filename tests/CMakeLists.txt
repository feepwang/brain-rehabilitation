include(GoogleTest)
find_package(GTest CONFIG REQUIRED)

add_executable(tests_example example.cpp)
target_compile_features(tests_example INTERFACE cxx_std_14)
target_link_libraries(tests_example PRIVATE br GTest::gtest_main)
gtest_discover_tests(tests_example)