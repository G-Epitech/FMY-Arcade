add_library(sfml SHARED
        export.cpp
        GraphicsProvider.cpp
        GraphicsProvider.hpp
)
target_include_directories(sfml PUBLIC ${CMAKE_CURRENT_LIST_DIR}/src)
target_include_directories(sfml PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../..)
