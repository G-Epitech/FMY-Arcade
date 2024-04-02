project(sfml)
add_library(sfml SHARED
        export.cpp
        src/GraphicsProvider.cpp
        src/GraphicsProvider.hpp
        src/window/Window.cpp
        src/window/Window.hpp
        src/window/EventsHandler.cpp
        src/window/EventsHandler.hpp
        src/sound/Sound.cpp
        src/sound/Sound.hpp
        src/texture/Texture.cpp
        src/texture/Texture.hpp
        src/font/Font.cpp
        src/font/Font.hpp
        src/window/Renderer.cpp
        src/window/Renderer.hpp
)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/../common PRIVATE)

target_include_directories(sfml PUBLIC ${CMAKE_CURRENT_LIST_DIR}/src)
target_include_directories(sfml PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../..)
target_include_directories(sfml PUBLIC ${CMAKE_CURRENT_LIST_DIR}/..)

target_link_libraries(sfml sfml-graphics sfml-window sfml-system sfml-audio)
