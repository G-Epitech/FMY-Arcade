add_library(sfml SHARED
        export.cpp
#[[        src/GraphicsProvider.cpp
        src/GraphicsProvider.hpp
        src/window/Window.cpp
        src/window/Window.hpp]]
)
target_include_directories(sfml PUBLIC ${CMAKE_CURRENT_LIST_DIR}/src)
target_include_directories(sfml PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../..)
