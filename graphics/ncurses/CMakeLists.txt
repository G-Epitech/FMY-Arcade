add_library(ncurses SHARED
        export.cpp
)
target_include_directories(ncurses PUBLIC ${CMAKE_CURRENT_LIST_DIR}/src)
target_include_directories(ncurses PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../..)
