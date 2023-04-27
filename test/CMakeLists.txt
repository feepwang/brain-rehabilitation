if (BR_ENABLE_TESTS)
    include(GoogleTest)

    find_package(PkgConfig REQUIRED)
    pkg_check_modules(GTest REQUIRED IMPORTED_TARGET gtest_main)

    add_executable(
        sort
        sort.cpp
    )
    target_link_libraries(
        sort
        PkgConfig::GTest
    )

    gtest_discover_tests(sort)
endif()