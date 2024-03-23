add_library(br SHARED br.cpp)
set_target_properties(br PROPERTIES 
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF)
target_link_libraries(br PUBLIC fmt::fmt)

install(TARGETS br
            DESTINATION lib)
install(DIRECTORY  "${CMAKE_SOURCE_DIR}/include/br"
            DESTINATION include)
