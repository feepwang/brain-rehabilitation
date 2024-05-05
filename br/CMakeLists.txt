if (BR_ENABLE_SHARED)
        add_library(br-shared SHARED br.cpp)
        set_target_properties(br-shared PROPERTIES 
                CXX_STANDARD 14
                CXX_STANDARD_REQUIRED ON
                CXX_EXTENSIONS OFF)
        target_link_libraries(br-shared PUBLIC fmt::fmt-header-only)
        add_library(br ALIAS br-shared)
        install(TARGETS br-shared
                    DESTINATION lib)
        install(DIRECTORY  "${CMAKE_SOURCE_DIR}/br"
                    DESTINATION include
                    FILES_MATCHING 
                    PATTERN "*.h")
else ()
        add_library(br-static STATIC br.cpp)
        set_target_properties(br-static PROPERTIES 
                CXX_STANDARD 14
                CXX_STANDARD_REQUIRED ON
                CXX_EXTENSIONS OFF)
        target_link_libraries(br-static PUBLIC fmt::fmt-header-only)
        add_library(br ALIAS br-static)
        install(TARGETS br-static
                    DESTINATION lib
                    FILES_MATCHING 
                    PATTERN "*.h")
        install(DIRECTORY  "${CMAKE_SOURCE_DIR}/br"
                    DESTINATION include)
endif ()

