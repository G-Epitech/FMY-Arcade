add_library(snake SHARED
        export.cpp
)
target_include_directories(snake PUBLIC ${CMAKE_CURRENT_LIST_DIR}/src)
target_include_directories(snake PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../..)
