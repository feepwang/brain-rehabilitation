if (BR_ENABLE_TESTS)
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(GTest IMPORTED_TARGET gtest_main)

    if (NOT GTest_FOUND)
        message(NOTICE "GTest Not Fount in environment\ncmake is going to download googletest over network")
        include(FetchContent)
        if(POLICY CMP0135)
            cmake_policy(SET CMP0135 NEW)
        endif()

        FetchContent_Declare(
          googletest
          URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
        )
        # For Windows: Prevent overriding the parent project's compiler/linker settings
        set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
        FetchContent_MakeAvailable(googletest)
    endif()

    add_executable(sort sort.cpp)
    if (NOT GTest_FOUND)
        target_link_libraries(sort GTest::gtest_main)
    else()
        target_link_libraries(sort PkgConfig::GTest)
    endif()

    include(GoogleTest)
    gtest_discover_tests(sort)
endif()