target_sources(arcade PRIVATE
    Core.cpp
    Core.hpp
)

add_subdirectory(exception)
add_subdirectory(loader)
add_subdirectory(utils)
add_subdirectory(menu)
