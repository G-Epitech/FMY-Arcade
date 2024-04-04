project(sdl2)
add_library(sdl2 SHARED
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
        src/types/window.hpp
        src/types/surface.hpp
        src/types/renderer.hpp
)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/../common PRIVATE)
add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/sdl)

target_include_directories(sdl2 PRIVATE ${CMAKE_CURRENT_LIST_DIR}/src)
target_include_directories(sdl2 PRIVATE ${CMAKE_CURRENT_LIST_DIR}/../..)
target_include_directories(sdl2 PRIVATE ${CMAKE_CURRENT_LIST_DIR}/..)
target_include_directories(sdl2 PRIVATE ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(sdl2
        SDL2 SDL2_image SDL2_ttf
)
